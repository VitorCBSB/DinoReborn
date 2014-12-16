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

	execute_collisions(bullets, enemies,
			[&](EntityPtr bullet, EntityPtr enemy) {
				world_ptr.lock()->get_event_manager().broadcast<Collision>(
						enemy, bullet);
			});
}

void CollisionSystem::execute_collisions(EntityMap& a_map, EntityMap& b_map,
		CollisionHandler collision_handler) {
	for (auto a_it = a_map.begin(); a_it != a_map.end(); a_it++) {
		auto a = a_it->second;
		for (auto b_it = b_map.begin(); b_it != b_map.end(); b_it++) {
			auto b = b_it->second;
			if (check_collision(*a, *b)) {
				collision_handler(a, b);
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
