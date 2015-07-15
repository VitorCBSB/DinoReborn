/*
 * PlayerAnimationManager.cpp
 *
 *  Created on: 07/01/2015
 *      Author: vitor
 */

#include "PlayerAnimationManager.h"

void PlayerAnimationManager::handle(const PlayerMoveLeft& event) {
	active_animations[2] = true;
}

void PlayerAnimationManager::handle(const PlayerMoveRight& event) {
	active_animations[3] = true;
}

void PlayerAnimationManager::handle(const PlayerMoveForward& event) {
	active_animations[1] = true;
}

void PlayerAnimationManager::handle(const PlayerMoveBackward& event) {
	active_animations[4] = true;
}

void PlayerAnimationManager::handle(const PlayerStopLeft& event) {
	active_animations[2] = false;
}

void PlayerAnimationManager::handle(const PlayerStopRight& event) {
	active_animations[3] = false;
}

void PlayerAnimationManager::handle(const PlayerStopForward& event) {
	active_animations[1] = false;
}

void PlayerAnimationManager::handle(const PlayerStopBackward& event) {
	active_animations[4] = false;
}

void PlayerAnimationManager::process_entity(Entity& entity, double dt) {
	int i;
	for (i = active_animations.size() - 1; i >= 0; i--) {
		if (active_animations[i]) {
			break;
		}
	}

	entity.get_component<AnimationComponent>()->animation.animation_state = i;
}
