/*
 * BulletRemovalSystem.cpp
 *
 *  Created on: 23/07/2014
 *      Author: vitor
 */

#include "BulletRemovalSystem.h"

void BulletRemovalSystem::handle(const PlayerBulletEnemyCollision& event) {
	auto bullet_position = event.bullet.get().get_component<PositionComponent>();
	EntityFactory::create_explosion(*(world_ptr.lock()),
			new PositionComponent(*bullet_position));
	world_ptr.lock()->remove_entity(event.bullet.get().get_id());
}

void BulletRemovalSystem::process_entity(Entity& entity, double dt) {
	auto bullet_position = entity.get_component<PositionComponent>()->position;

	// TODO - Remove magic numbers
	if (bullet_position.x < 0 || bullet_position.x > 800
			|| bullet_position.y < 0 || bullet_position.y > 600) {
		world_ptr.lock()->remove_entity(entity.get_id());
	}
}
