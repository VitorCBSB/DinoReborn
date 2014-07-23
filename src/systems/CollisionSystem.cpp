/*
 * CollisionSystem.cpp
 *
 *  Created on: 22/07/2014
 *      Author: vitor
 */

#include "CollisionSystem.h"

void CollisionSystem::process_entities(std::map<uint64_t, EntityPtr>& entities,
		double dt) {
	auto bullets =
			world_ptr.lock()->get_group_manager().get_entities_from_group(
					"player_bullets");
	auto enemies =
			world_ptr.lock()->get_group_manager().get_entities_from_group(
					"enemies");

	for (auto it = bullets.begin(); it != bullets.end();) {
		auto actual = it++;
		auto bullet = actual->second;

		auto bullet_circle = bullet->get_component<BoundingCircleComponent>();
		auto bullet_position = bullet->get_component<PositionComponent>();

		for (auto enem_it = enemies.begin(); enem_it != enemies.end();) {
			auto enemy_actual = enem_it++;
			auto enemy = enemy_actual->second;

			auto enemy_circle = enemy->get_component<BoundingCircleComponent>();
			auto enemy_position = enemy->get_component<PositionComponent>();

			if (enemy_position->position.distance(bullet_position->position)
					< enemy_circle->radius + bullet_circle->radius) {
				world_ptr.lock()->get_event_manager().broadcast<Collision>(
						enemy, bullet);
			}
		}
	}
}

void CollisionSystem::process_entity(Entity& entity, double dt) {
}
