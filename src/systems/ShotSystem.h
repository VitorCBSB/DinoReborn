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
#include "../components/marker/PlayerBulletMarker.h"

class ShotSystem: public SingleEntitySystem {
public:
	ShotSystem(WorldPtr world_ptr) :
			SingleEntitySystem(world_ptr) {
		add_aspect(new AllOfAspect<ShotComponent, PositionComponent>());
	}

	void process_entity(Entity& entity, double dt);
};

#endif /* SHOTSYSTEM_H_ */
