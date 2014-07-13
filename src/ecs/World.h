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
#include <memory>
#include <stdint.h>
#include <map>
#include <vector>

class World {
private:
	std::vector<SystemPtr> systems;
	std::map<uint64_t, EntityPtr> entities;

	uint64_t new_entity_id = 0;

public:
	World();
	virtual ~World();

	Entity& create_entity();
	void remove_entity(uint64_t id);
	void add_system(System* system);
	void process(double dt);
};

#endif /* WORLD_H_ */
