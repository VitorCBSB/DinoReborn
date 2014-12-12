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

class BulletRotationSystem: public System {
public:
	BulletRotationSystem(WorldPtr world_ptr) :
			System(world_ptr) {
	}

	void process_entities(double dt);
	void process_entity(Entity& entity, double dt);
};

#endif /* BULLETROTATIONSYSTEM_H_ */
