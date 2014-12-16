/*
 * CollisionSystem.cpp
 *
 *  Created on: 22/07/2014
 *      Author: vitor
 */

#include "CollisionSystem.h"

void CollisionSystem::process_entities(double dt) {
	auto bullets =
			world_ptr.lock()->get_group_manager().get_entities_from_group(
					"player_bullets");
	auto enemies =
			world_ptr.lock()->get_group_manager().get_entities_from_group(
					"enemies");

	for (auto it = bullets.begin(); it != bullets.end();) {
		auto actual = it++;
		auto bullet = actual->second;

		for (auto enem_it = enemies.begin(); enem_it != enemies.end();) {
			auto enemy_actual = enem_it++;
			auto enemy = enemy_actual->second;

			if (check_collision(*bullet, *enemy)) {
				world_ptr.lock()->get_event_manager().broadcast<Collision>(
						enemy, bullet);
			}
		}
	}
}

bool CollisionSystem::check_collision(Entity& a, Entity& b) {
	auto a_circle = a.get_component<BoundingCircleComponent>();
	auto a_position = a.get_component<PositionComponent>();

	auto b_circle = b.get_component<BoundingCircleComponent>();
	auto b_position = b.get_component<PositionComponent>();

	return a_position->position.distance(b_position->position)
					< a_circle->radius + b_circle->radius;
}
