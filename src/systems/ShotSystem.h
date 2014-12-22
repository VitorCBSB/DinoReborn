/*
 * ShotSystem.h
 *
 *  Created on: 17/12/2014
 *      Author: vitor
 */

#ifndef SHOTSYSTEM_H_
#define SHOTSYSTEM_H_

#include "../ecs/System.h"
#include "../EntityFactory.h"
#include "../components/ShotComponent.h"
#include "../components/PositionComponent.h"
#include "../components/VelocityComponent.h"

class ShotSystem: public System {
public:
	ShotSystem(WorldPtr world_ptr) :
			System(world_ptr) {
		add_aspect(new AllOfAspect<ShotComponent, PositionComponent>());
	}

	void process_entity(Entity& entity, double dt);
};

#endif /* SHOTSYSTEM_H_ */
