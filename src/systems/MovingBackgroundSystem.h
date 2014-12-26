/*
 * MovingBackgroundSystem.h
 *
 *  Created on: 26/12/2014
 *      Author: vitor
 */

#ifndef MOVINGBACKGROUNDSYSTEM_H_
#define MOVINGBACKGROUNDSYSTEM_H_

#include "../ecs/VECS.h"
#include "../components/PositionComponent.h"

class MovingBackgroundSystem: public System {
public:
	MovingBackgroundSystem(WorldPtr world_ptr) :
			System(world_ptr) {
	}

	void process_entities(double dt);
	void process_entity(Entity& entity, double dt);
};

#endif /* MOVINGBACKGROUNDSYSTEM_H_ */
