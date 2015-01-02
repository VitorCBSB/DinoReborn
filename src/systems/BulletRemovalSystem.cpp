/*
 * BulletRemovalSystem.cpp
 *
 *  Created on: 23/07/2014
 *      Author: vitor
 */

#include "BulletRemovalSystem.h"

void BulletRemovalSystem::handle(const PlayerBulletEnemyCollision& event) {
	auto bullet_position = event.bullet->get_component<PositionComponent>();
	EntityFactory::create_explosion(*(world_ptr.lock()),
			new PositionComponent(*bullet_position));
	world_ptr.lock()->remove_entity(event.bullet);
}

void BulletRemovalSystem::process_entities(double dt) {
	auto bullets =
			world_ptr.lock()->get_group_manager().get_entities_from_group(
					"bullets");

	for (auto it = bullets.begin(); it != bullets.end();) {
		auto actual = it++;
		process_entity(*(actual->second), dt);
	}
}

void BulletRemovalSystem::process_entity(Entity& entity, double dt) {
	auto bullet_position = entity.get_component<PositionComponent>()->position;

	// TODO - Remove magic numbers
	if (bullet_position.x < 0 || bullet_position.x > 800
			|| bullet_position.y < 0 || bullet_position.y > 600) {
		world_ptr.lock()->remove_entity(entity.get_id());
	}
}
