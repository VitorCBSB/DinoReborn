/*
 * Direction.cpp
 *
 *  Created on: 08/08/2014
 *      Author: vitor
 */

#include "Direction.h"

// FIXME: Aim is not working.
float Direction::get_angle(World& world, Entity& bullet) {
	auto bullet_position = bullet.get_component<PositionComponent>()->position;
	auto bullet_velocity = bullet.get_component<VelocityComponent>()->velocity;
	Vector2 player_position;
	if (world.get_tag_manager().get_entity("player") != nullptr) {
		player_position =
				world.get_tag_manager().get_entity("player")->get_component<
						PositionComponent>()->position;
	}
	auto vector_to_player = player_position - bullet_position;

	switch (type) {
	case ABSOLUTE:
		return direction.eval();
	case RELATIVE:
		return bullet.get_component<VelocityComponent>()->velocity.angle()
				+ direction.eval();
	case AIM:
		return direction.eval() + vector_to_player.angle();
	default:
		return 0.0;
	}
}
