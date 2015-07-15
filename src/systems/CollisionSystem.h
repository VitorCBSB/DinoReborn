/*
 * CollisionSystem.h
 *
 *  Created on: 22/07/2014
 *      Author: vitor
 */

#ifndef COLLISIONSYSTEM_H_
#define COLLISIONSYSTEM_H_

#include "../ecs/VECS.h"
#include "../components/BoundingCircleComponent.h"
#include "../components/PositionComponent.h"
#include "../components/marker/PlayerBulletMarker.h"
#include "../components/marker/EnemyMarker.h"
#include "../events/PlayerBulletEnemyCollision.h"
#include <functional>

class CollisionSystem: public InteractSystem {
private:
	bool check_collision(Entity& a, Entity& b);

public:
	CollisionSystem(WorldPtr world_ptr) :
			InteractSystem(world_ptr) {
		add_aspect_A(new AllOfAspect<PositionComponent, PlayerBulletMarker>());
		add_aspect_B(new AllOfAspect<PositionComponent, EnemyMarker>());
	}

	void process_pair(Entity& entityA, Entity& entityB, double dt);
};

#endif /* COLLISIONSYSTEM_H_ */
