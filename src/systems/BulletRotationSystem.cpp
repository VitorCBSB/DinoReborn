/*
 * BulletRotationSystem.cpp
 *
 *  Created on: 08/08/2014
 *      Author: vitor
 */

#include "BulletRotationSystem.h"

void BulletRotationSystem::process_entities(
		std::map<uint64_t, EntityPtr>& entities, double dt) {
	auto bullets =
			world_ptr.lock()->get_group_manager().get_entities_from_group(
					"bullets");

	for (auto& bullet : bullets) {
		process_entity(*bullet.second, dt);
	}
}

void BulletRotationSystem::process_entity(Entity& entity, double dt) {
	auto animation = entity.get_component<AnimationComponent>();
	auto velocity = entity.get_component<VelocityComponent>();

	animation->animation.set_angle(velocity->velocity.angle());
}
