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
	std::function<void(std::vector<std::reference_wrapper<Entity>>&)> preprocess
			= [](std::vector<std::reference_wrapper<Entity>>&){};

public:
	SingleEntitySystem(WorldPtr world_ptr) : System(world_ptr) {
	}
	virtual ~SingleEntitySystem() {
	}

	void set_preprocess(std::function<void(std::vector<std::reference_wrapper<Entity>>&)>
                preprocess_function) {
		preprocess = preprocess_function;
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
		std::vector<std::reference_wrapper<Entity>> entities;
		for (auto& entity : valid_entities) {
			entities.emplace_back(*entity.second);
		}
		preprocess(entities);
		for (auto& entity : entities) {
			process_entity(entity.get(), dt);
		}
	}

	virtual void process_entity(Entity& entity, double dt) = 0;
};

#endif /* ECS_SINGLEENTITYSYSTEM_H_ */
