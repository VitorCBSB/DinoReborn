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
#include "../EntityFactory.h"

class BulletRemovalSystem: public System {
public:
	BulletRemovalSystem(WorldPtr world_ptr) :
			System(world_ptr) {
		this->world_ptr.lock()->get_event_manager().subscribe<
				PlayerBulletEnemyCollision>(*this);
	}

	void process_entities(double dt);
	void process_entity(Entity& entity, double dt);

	void handle(const PlayerBulletEnemyCollision& event);
};

#endif /* BULLETREMOVALSYSTEM_H_ */
