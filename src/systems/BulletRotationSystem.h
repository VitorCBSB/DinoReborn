/*
 * BulletRotationSystem.h
 *
 *  Created on: 08/08/2014
 *      Author: vitor
 */

#ifndef BULLETROTATIONSYSTEM_H_
#define BULLETROTATIONSYSTEM_H_

#include "../ecs/VECS.h"
#include "../components/VelocityComponent.h"
#include "../components/AnimationComponent.h"
#include "../components/marker/BulletMarker.h"

class BulletRotationSystem: public SingleEntitySystem {
public:
	BulletRotationSystem(WorldPtr world_ptr) :
			SingleEntitySystem(world_ptr) {
		add_aspect(new AllOfAspect<BulletMarker>());
	}

	void process_entity(Entity& entity, double dt);
};

#endif /* BULLETROTATIONSYSTEM_H_ */
