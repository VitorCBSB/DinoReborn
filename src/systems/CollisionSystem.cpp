/*
 * CollisionSystem.cpp
 *
 *  Created on: 22/07/2014
 *      Author: vitor
 */

#include "CollisionSystem.h"

bool CollisionSystem::check_collision(Entity& a, Entity& b) {
	auto a_circle = a.get_component<BoundingCircleComponent>();
	auto a_position = a.get_component<PositionComponent>();

	auto b_circle = b.get_component<BoundingCircleComponent>();
	auto b_position = b.get_component<PositionComponent>();

	return a_position->position.distance(b_position->position)
			< a_circle->radius + b_circle->radius;
}

void CollisionSystem::process_pair(Entity& entityA, Entity& entityB, double dt) {
	if (check_collision(entityA, entityB)) {
		world_ptr.lock()->get_event_manager().broadcast<
				PlayerBulletEnemyCollision>(entityA, entityB);
	}
}
