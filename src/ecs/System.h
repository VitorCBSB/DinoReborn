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

class World;

typedef std::shared_ptr<World> WorldPtr;

class System {
protected:
	std::vector<AspectPtr> aspects;
	std::weak_ptr<World> world_ptr;
	EntityMap valid_entities;

public:
	System(WorldPtr world_ptr) :
			world_ptr(world_ptr) {
	}
	virtual ~System() {
	}

	void add_aspect(Aspect* aspect) {
		aspects.push_back(AspectPtr(aspect));
	}

	void remove_entity(uint64_t entity_id) {
		valid_entities.erase(entity_id);
	}

	void update_entity(EntityPtr e) {
		for (auto& aspect : aspects) {
			if (!aspect->validate(*e)) {
				valid_entities.erase(e->get_id());
				return;
			}
		}
		valid_entities[e->get_id()] = e;
	}

	virtual void process_entities(double dt) {
		for (auto it = valid_entities.begin(); it != valid_entities.end();
				it++) {
			process_entity(*(it->second), dt);
		}
	}

	virtual void process_entity(Entity& entity, double dt) = 0;
};

typedef std::unique_ptr<System> SystemPtr;

#endif /* SYSTEM_H_ */
