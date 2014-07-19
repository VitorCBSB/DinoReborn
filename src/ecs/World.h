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
#include <memory>
#include <stdint.h>
#include <map>
#include <string>

class World {
private:
	std::vector<SystemPtr> systems;
	std::map<uint64_t, EntityPtr> entities;
	EventManager event_manager;

	uint64_t new_entity_id = 0;

public:
	int next_state;

	World(int initial_state) :
			next_state(initial_state) {
	}

	Entity& create_entity();
	void remove_entity(uint64_t id);
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
};

#endif /* WORLD_H_ */
