/*
 * SingleEntitySystem.h
 *
 *  Created on: 14/07/2015
 *      Author: vitor
 */

#ifndef ECS_SINGLEENTITYSYSTEM_H_
#define ECS_SINGLEENTITYSYSTEM_H_

#include "System.h"
#include "Entity.h"
#include "Aspect.h"
#include <functional>

class SingleEntitySystem : public System {
protected:
	std::vector<AspectPtr> aspects;
	EntityMap valid_entities;

public:
	SingleEntitySystem(WorldPtr world_ptr) : System(world_ptr) {
	}
	virtual ~SingleEntitySystem() {
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

	void process(double dt) {
		preprocess();
		for (auto& entity : valid_entities) {
			process_entity(*entity.second, dt);
		}
	}

	virtual void process_entity(Entity& entity, double dt) = 0;
};

#endif /* ECS_SINGLEENTITYSYSTEM_H_ */
