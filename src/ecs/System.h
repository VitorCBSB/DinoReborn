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
	WorldPtr world_ptr;

public:
	System(WorldPtr world_ptr) :
			world_ptr(world_ptr) {
	}
	virtual ~System() {
	}

	void add_aspect(Aspect* aspect) {
		aspects.push_back(AspectPtr(aspect));
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

	virtual void process_entity(Entity& entity, double dt) = 0;
};

typedef std::unique_ptr<System> SystemPtr;

#endif /* SYSTEM_H_ */
