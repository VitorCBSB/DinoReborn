/*
 * System.h
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <memory>
#include <vector>
#include <map>
#include <stdint.h>
#include <typeinfo>
#include "Aspect.h"
#include "Entity.h"
#include "Event.h"

class SystemBase {
public:
	virtual ~SystemBase() {}
	virtual void process_entities(std::map<uint64_t, EntityPtr>& entities, double dt) = 0;
	virtual void add_subscriber(std::shared_ptr<SystemBase> listener) = 0;
	virtual void handle_event(Event& event) = 0;
};

template <typename T>
class System : public SystemBase {
protected:
	std::vector<AspectPtr> aspects;
	std::vector<std::shared_ptr<SystemBase>> listeners;

public:
	System() {
	}
	virtual ~System() {
	}

	void add_aspect(Aspect* aspect) {
		aspects.push_back(AspectPtr(aspect));
	}

	void add_subscriber(std::shared_ptr<SystemBase> subscriber) {
		listeners.push_back(subscriber);
	}

	bool validate(const Entity& e) const {
		for (auto& aspect : aspects) {
			if (!aspect->validate(e)) {
				return false;
			}
		}
		return true;
	}

	virtual void process_entities(std::map<uint64_t, EntityPtr>& entities,
			double dt) {
		for (auto& entity_entry : entities) {
			if (validate(*(entity_entry.second))) {
				process_entity(*(entity_entry.second), dt);
			}
		}
	}

	void broadcast(Event& event) {
		for (auto& listener : listeners) {
			listener->handle_event(event);
		}
	}

	virtual void process_entity(Entity& entity, double dt) = 0;
	virtual void handle_event(Event& event) {
	}

	static std::string name() {
		return std::string(typeid(T).name());
	}
};

typedef std::shared_ptr<SystemBase> SystemPtr;

#endif /* SYSTEM_H_ */
