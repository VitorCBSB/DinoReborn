/*
 * PlayerInputHandler.cpp
 *
 *  Created on: 17/07/2014
 *      Author: vitor
 */

#include "PlayerInputHandler.h"

void PlayerInputHandler::handle(const KeyboardDown& event) {
	auto player = world_ptr.lock()->get_tag_manager().get_entity("player");
	if (!player) {
		return;
	}

	auto v = player->get_component<VelocityComponent>();
	auto shot_component = player->get_component<ShotComponent>();
	EntityPtr bullet;

	switch (event.key) {
	case SDL_SCANCODE_LEFT:
		v->velocity += Vector2(-1, 0) * SPEED;
		break;
	case SDL_SCANCODE_RIGHT:
		v->velocity += Vector2(1, 0) * SPEED;
		break;
	case SDL_SCANCODE_UP:
		v->velocity += Vector2(0, -1) * SPEED;
		break;
	case SDL_SCANCODE_DOWN:
		v->velocity += Vector2(0, 1) * SPEED;
		break;
	case SDL_SCANCODE_Z:
		shot_component->shooting = true;
		break;
	default:
		break;
	}
}

void PlayerInputHandler::handle(const KeyboardUp& event) {
	auto player = world_ptr.lock()->get_tag_manager().get_entity("player");
	if (!player) {
		return;
	}

	auto v = player->get_component<VelocityComponent>();
	auto shot_component = player->get_component<ShotComponent>();

	switch (event.key) {
	case SDL_SCANCODE_LEFT:
		v->velocity -= Vector2(-1, 0) * SPEED;
		break;
	case SDL_SCANCODE_RIGHT:
		v->velocity -= Vector2(1, 0) * SPEED;
		break;
	case SDL_SCANCODE_UP:
		v->velocity -= Vector2(0, -1) * SPEED;
		break;
	case SDL_SCANCODE_DOWN:
		v->velocity -= Vector2(0, 1) * SPEED;
		break;
	case SDL_SCANCODE_Z:
		shot_component->shooting = false;
		break;
	default:
		break;
	}
}
