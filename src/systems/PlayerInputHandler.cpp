/*
 * PlayerInputHandler.cpp
 *
 *  Created on: 17/07/2014
 *      Author: vitor
 */

#include "PlayerInputHandler.h"

void PlayerInputHandler::handle(const KeyboardDown& event) {
	auto entities = world_ptr->get_group_manager().get_entities_from_group("player");
	auto& player = (*(entities.begin())).second;
	auto v = player->get_component<VelocityComponent>();
	auto p = player->get_component<PositionComponent>();

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
		EntityFactory::create_bullet(*world_ptr, new PositionComponent(*p));
		break;
	default:
		break;
	}
}

void PlayerInputHandler::handle(const KeyboardUp& event) {
	auto entities = world_ptr->get_group_manager().get_entities_from_group("player");
	auto& player = (*(entities.begin())).second;
	auto v = player->get_component<VelocityComponent>();

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
	default:
		break;
	}
}
