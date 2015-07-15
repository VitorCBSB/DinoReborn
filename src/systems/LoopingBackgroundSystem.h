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
#include "../components/marker/BackgroundMarker.h"

class LoopingBackgroundSystem: public SingleEntitySystem {
public:
	LoopingBackgroundSystem(WorldPtr world_ptr) :
			SingleEntitySystem(world_ptr) {
		add_aspect(new AllOfAspect<BackgroundMarker>());
	}

	void process_entity(Entity& entity, double dt);
};

#endif /* LOOPINGBACKGROUNDSYSTEM_H_ */
