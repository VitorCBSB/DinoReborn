/*
 * IndependentSystem.h
 *
 *  Created on: 14/07/2015
 *      Author: vitor
 */

#ifndef ECS_INDEPENDENTSYSTEM_H_
#define ECS_INDEPENDENTSYSTEM_H_

#include "System.h"
#include "Entity.h"

class IndependentSystem : public System {
protected:
	IndependentSystem(WorldPtr world_ptr) : System(world_ptr) {
	}
	virtual ~IndependentSystem() {
	}

	void remove_entity(uint64_t entity_id) {
	}

	void update_entity(EntityPtr e) {
	}
};

#endif /* ECS_INDEPENDENTSYSTEM_H_ */
