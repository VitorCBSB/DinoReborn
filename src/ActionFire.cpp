/*
 * ActionFire.cpp
 *
 *  Created on: 05/08/2014
 *      Author: vitor
 */

#include "ActionFire.h"

bool ActionFire::update(World& world, Entity& bullet, double dt) {
	auto angle = direction.get_angle(world, bullet);
	auto angle_radians = ((M_PI / 180.0) * angle);
	auto speed_val = speed.eval();

	EntityFactory::create_bullet(world,
			new PositionComponent(*(bullet.get_component<PositionComponent>())),
			new VelocityComponent(speed_val * cos(angle_radians),
					speed_val * sin(angle_radians)), bullet_definition);
	return true;
}
