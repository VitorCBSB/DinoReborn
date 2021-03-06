/*
 * PlayerInputHandler.cpp
 *
 *  Created on: 17/07/2014
 *      Author: vitor
 */

#include "PlayerInputHandler.h"

void PlayerInputHandler::handle(const PlayerMoveLeft& event) {
	auto player = world_ptr.lock()->get_tag_manager().get_entity("player");
	if (!player) {
		return;
	}

	auto v = player->get_component<VelocityComponent>();
	v->velocity += Vector2(-1, 0) * SPEED;
}

void PlayerInputHandler::handle(const PlayerStopLeft& event) {
	auto player = world_ptr.lock()->get_tag_manager().get_entity("player");
	if (!player) {
		return;
	}

	auto v = player->get_component<VelocityComponent>();
	v->velocity -= Vector2(-1, 0) * SPEED;
}

void PlayerInputHandler::handle(const PlayerMoveRight& event) {
	auto player = world_ptr.lock()->get_tag_manager().get_entity("player");
	if (!player) {
		return;
	}

	auto v = player->get_component<VelocityComponent>();
	v->velocity += Vector2(1, 0) * SPEED;
}

void PlayerInputHandler::handle(const PlayerStopRight& event) {
	auto player = world_ptr.lock()->get_tag_manager().get_entity("player");
	if (!player) {
		return;
	}

	auto v = player->get_component<VelocityComponent>();
	v->velocity -= Vector2(1, 0) * SPEED;
}

void PlayerInputHandler::handle(const PlayerMoveForward& event) {
	auto player = world_ptr.lock()->get_tag_manager().get_entity("player");
	if (!player) {
		return;
	}

	auto v = player->get_component<VelocityComponent>();
	v->velocity += Vector2(0, -1) * SPEED;
}

void PlayerInputHandler::handle(const PlayerStopForward& event) {
	auto player = world_ptr.lock()->get_tag_manager().get_entity("player");
	if (!player) {
		return;
	}

	auto v = player->get_component<VelocityComponent>();
	v->velocity -= Vector2(0, -1) * SPEED;
}

void PlayerInputHandler::handle(const PlayerMoveBackward& event) {
	auto player = world_ptr.lock()->get_tag_manager().get_entity("player");
	if (!player) {
		return;
	}

	auto v = player->get_component<VelocityComponent>();
	v->velocity += Vector2(0, 1) * SPEED;
}

void PlayerInputHandler::handle(const PlayerStopBackward& event) {
	auto player = world_ptr.lock()->get_tag_manager().get_entity("player");
	if (!player) {
		return;
	}

	auto v = player->get_component<VelocityComponent>();
	v->velocity -= Vector2(0, 1) * SPEED;
}

void PlayerInputHandler::handle(const PlayerShoot& event) {
	auto player = world_ptr.lock()->get_tag_manager().get_entity("player");
	if (!player) {
		return;
	}

	auto shot_component = player->get_component<ShotComponent>();
	shot_component->shooting = true;
}

void PlayerInputHandler::handle(const PlayerStopShooting& event) {
	auto player = world_ptr.lock()->get_tag_manager().get_entity("player");
	if (!player) {
		return;
	}

	auto shot_component = player->get_component<ShotComponent>();
	shot_component->shooting = false;
}
