/*
 * AnimationManagerSystem.cpp
 *
 *  Created on: 25/07/2014
 *      Author: vitor
 */

#include "AnimationManagerSystem.h"

void AnimationManagerSystem::process_entity(Entity& entity, double dt) {
	auto animation = entity.get_component<AnimationComponent>();

	animation->animation.update();
	if (animation->animation.is_done()) {
		world_ptr.lock()->remove_entity(entity.get_id());
	}
}
