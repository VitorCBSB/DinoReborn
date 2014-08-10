/*
 * ActionChangeDirection.cpp
 *
 *  Created on: 04/08/2014
 *      Author: vitor
 */

#include "ActionChangeDirection.h"

// FIXME: I'm not working!!
bool ActionChangeDirection::update(World& world, Entity& bullet, double dt) {
	if (!started) {
		started = true;
		timer.start((int) time.eval());
		original_angle =
				bullet.get_component<VelocityComponent>()->velocity.angle();
		direction_difference = original_angle
				- direction.get_angle(world, bullet);
	}
	timer.update();

	auto exec_time = time.eval();
	last_time = elapsed_time;
	elapsed_time = ((int) exec_time - timer.remaining_time());
	auto time_difference = (float) (elapsed_time - last_time);

	auto step =
			exec_time == 0.0 ?
					direction_difference :
					(time_difference / exec_time) * direction_difference;
	auto bullet_velocity = bullet.get_component<VelocityComponent>();
	bullet_velocity->velocity = bullet_velocity->velocity.rotate(step);

	return timer.is_done();
}
