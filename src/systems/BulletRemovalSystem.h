/*
 * BulletRemovalSystem.h
 *
 *  Created on: 23/07/2014
 *      Author: vitor
 */

#ifndef BULLETREMOVALSYSTEM_H_
#define BULLETREMOVALSYSTEM_H_

#include "../ecs/VECS.h"
#include "../events/PlayerBulletEnemyCollision.h"
#include "../components/PositionComponent.h"
#include "../components/marker/BulletMarker.h"
#include "../EntityFactory.h"

class BulletRemovalSystem: public SingleEntitySystem {
public:
	BulletRemovalSystem(WorldPtr world_ptr) :
			SingleEntitySystem(world_ptr) {
		add_aspect(new AllOfAspect<BulletMarker, PositionComponent>());
		this->world_ptr.lock()->get_event_manager().subscribe<
				PlayerBulletEnemyCollision>(*this);
	}

	void process_entity(Entity& entity, double dt);

	void handle(const PlayerBulletEnemyCollision& event);
};

#endif /* BULLETREMOVALSYSTEM_H_ */
