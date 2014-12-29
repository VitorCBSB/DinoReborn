/*
 * LoopingBackgroundSystem.h
 *
 *  Created on: 26/12/2014
 *      Author: vitor
 */

#ifndef LOOPINGBACKGROUNDSYSTEM_H_
#define LOOPINGBACKGROUNDSYSTEM_H_

#include "../ecs/VECS.h"
#include "../components/PositionComponent.h"

class LoopingBackgroundSystem: public System {
public:
	LoopingBackgroundSystem(WorldPtr world_ptr) :
			System(world_ptr) {
	}

	void process_entities(double dt);
	void process_entity(Entity& entity, double dt);
};

#endif /* LOOPINGBACKGROUNDSYSTEM_H_ */
