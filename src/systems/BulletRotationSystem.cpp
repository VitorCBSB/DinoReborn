/*
 * BulletRotationSystem.cpp
 *
 *  Created on: 08/08/2014
 *      Author: vitor
 */

#include "BulletRotationSystem.h"

void BulletRotationSystem::process_entity(Entity& entity, double dt) {
	auto animation = entity.get_component<AnimationComponent>();
	auto velocity = entity.get_component<VelocityComponent>();

	if (velocity->velocity.length() == 0) {
		return;
	}

	animation->animation.set_angle(velocity->velocity.angle());
}
