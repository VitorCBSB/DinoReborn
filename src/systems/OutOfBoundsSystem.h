/*
 * OutOfBoundsSystem.h
 *
 *  Created on: 23/12/2014
 *      Author: vitor
 */

#ifndef OUTOFBOUNDSSYSTEM_H_
#define OUTOFBOUNDSSYSTEM_H_

#include "../ecs/VECS.h"
#include "../components/PositionComponent.h"
#include <algorithm>

class OutOfBoundsSystem: public System {
public:
	OutOfBoundsSystem(WorldPtr world_ptr) :
			System(world_ptr) {
	}

	void process_entities(double dt);
	void process_entity(Entity& entity, double dt) {
	}
};

#endif /* OUTOFBOUNDSSYSTEM_H_ */
