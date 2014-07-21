/*
 * World.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef WORLD_H_
#define WORLD_H_

#include "Entity.h"
#include "System.h"
#include "Aspect.h"
#include "EventManager.h"
#include "GroupManager.h"
#include <memory>
#include <stdint.h>
#include <map>
#include <string>

class World {
private:
	std::vector<SystemPtr> systems;
	std::map<uint64_t, EntityPtr> entities;
	EventManager event_manager;
	GroupManager group_manager;

	uint64_t new_entity_id = 0;

	void remove_entity_from_everything(uint64_t id);

public:
	int next_state;

	World(int initial_state) :
			next_state(initial_state) {
	}

	EntityPtr create_entity();
	void remove_entity(uint64_t id);
	void remove_entity(Entity& entity);
	int process(double dt);

	template<typename T, typename ... Args>
	void add_system(Args ... args) {
		systems.push_back(SystemPtr(new T(args...)));
	}

	template<typename T>
	std::vector<std::reference_wrapper<Entity>> get_entities_with_component() {
		std::vector<std::reference_wrapper<Entity>> result;
		for (auto& entity_entry : entities) {
			if (entity_entry.second->has_component<T>()) {
				result.push_back(*(entity_entry.second));
			}
		}
		return result;
	}

	EventManager& get_event_manager() {
		return event_manager;
	}

	GroupManager& get_group_manager() {
		return group_manager;
	}
};

typedef std::shared_ptr<World> WorldPtr;

#endif /* WORLD_H_ */
