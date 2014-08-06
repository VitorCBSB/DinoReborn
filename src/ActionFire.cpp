/*
 * ActionFire.cpp
 *
 *  Created on: 05/08/2014
 *      Author: vitor
 */

#include "ActionFire.h"

bool ActionFire::update(World& world, Entity& bullet, double dt) {
	auto angle = get_angle_based_on_type(world, bullet);
	auto angle_radians = ((M_PI / 180.0) * angle);
	auto speed_val = speed.eval();

	EntityFactory::create_bullet(world,
			new PositionComponent(*(bullet.get_component<PositionComponent>())),
			new VelocityComponent(speed_val * cos(angle_radians),
					speed_val * sin(angle_radians)), bullet_definition);
	return true;
}

float ActionFire::get_angle_based_on_type(World& world, Entity& bullet) {
	auto bullet_position = bullet.get_component<PositionComponent>()->position;
	auto player_position =
			world.get_tag_manager().get_entity("player")->get_component<
					PositionComponent>()->position;
	auto position_difference = player_position - bullet_position;

	switch (direction_type) {
	case ABSOLUTE:
		return direction.eval();
	case RELATIVE:
		return bullet.get_component<VelocityComponent>()->velocity.angle()
				+ direction.eval();
	case AIM:
		return atan2(position_difference.y, position_difference.x);
	default:
		return 0.0;
	}
}
