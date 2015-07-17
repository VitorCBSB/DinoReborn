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
	std::weak_ptr<World> world_ptr;

public:
	System(WorldPtr world_ptr) :
			world_ptr(world_ptr) {
	}
	virtual ~System() {
	}

	virtual void remove_entity(uint64_t entity_id) = 0;

	virtual void update_entity(EntityPtr e) = 0;

	virtual void process(double dt) = 0;
};

typedef std::unique_ptr<System> SystemPtr;

#endif /* SYSTEM_H_ */
