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
#include "../components/marker/PlayerMarker.h"
#include <algorithm>

class OutOfBoundsSystem: public SingleEntitySystem {
public:
	OutOfBoundsSystem(WorldPtr world_ptr) :
			SingleEntitySystem(world_ptr) {
		add_aspect(new AllOfAspect<PlayerMarker, PositionComponent>());
	}

	void process_entity(Entity& entity, double dt);
};

#endif /* OUTOFBOUNDSSYSTEM_H_ */
