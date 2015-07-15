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
#include "Component.h"
#include "EventManager.h"
#include "GroupManager.h"
#include "TagManager.h"
#include <memory>
#include <stdint.h>
#include <map>
#include <string>

class World {
private:
	std::vector<SystemPtr> systems;
	EntityMap entities;

	EntityMap changed_entities;
	EntityMap removed_entities;

	EventManager event_manager;
	TagManager tag_manager;

	uint64_t new_entity_id = 0;

	void remove_entity_from_everything(uint64_t id);

public:
	int next_state;

	World(int initial_state) :
			next_state(initial_state) {
	}

	EntityPtr create_entity();
	void remove_entity(uint64_t id);
	void remove_entity(EntityPtr entity);
	int process(double dt);
	void flush_changes();

	template<typename T, typename ... Args>
	void assign_component(EntityPtr e, Args&& ... args) {
		e->assign_component<T>(args...);
		changed_entities[e->id] = e;
	}

	template<typename T>
	void assign_component(EntityPtr e, T* component) {
		e->assign_component(component);
		changed_entities[e->id] = e;
	}

	template<typename T>
	void remove_component(EntityPtr e) {
		e->remove_component<T>();
		changed_entities[e->id] = e;
	}

	template<typename T, typename ... Args>
	void add_system(Args ... args) {
		systems.push_back(SystemPtr(new T(args...)));
	}

	template<typename T>
	std::vector<EntityPtr> get_entities_with_component() {
		std::vector<EntityPtr> result;
		for (auto& entity_entry : entities) {
			if (entity_entry.second->has_component<T>()) {
				result.push_back(entity_entry.second);
			}
		}
		return result;
	}

	EventManager& get_event_manager() {
		return event_manager;
	}

	TagManager& get_tag_manager() {
		return tag_manager;
	}
};

typedef std::shared_ptr<World> WorldPtr;

#endif /* WORLD_H_ */
