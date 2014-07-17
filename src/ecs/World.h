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
	Entity& create_entity();
	void remove_entity(uint64_t id);
	void process(double dt);

	template<typename T, typename ... Args>
	void add_system(Args ... args) {
		systems.push_back(SystemPtr(new T(args...)));
	}

	EventManager& get_event_manager() {
		return event_manager;
	}
};

#endif /* WORLD_H_ */
