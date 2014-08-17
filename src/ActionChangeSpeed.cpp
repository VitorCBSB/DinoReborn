/*
 * ActionChangeSpeed.cpp
 *
 *  Created on: 01/08/2014
 *      Author: vitor
 */

#include "ActionChangeSpeed.h"

ActionChangeSpeed::ActionChangeSpeed(Expression speed, Expression time,
		ChangeSpeedType type) :
		speed(speed), time(time), type(type) {
}

bool ActionChangeSpeed::update(World& world, Entity& bullet, double dt) {
	if (!started) {
		started = true;
		original_velocity = bullet.get_component<VelocityComponent>()->velocity;

		auto target_velocity =
				type == ABSOLUTE ?
						speed.eval() :
						original_velocity.length() + speed.eval();
		auto scaling = target_velocity / original_velocity.length();
		scaling_difference = scaling - 1.0;
		timer.start((int) time.eval());
	}
	timer.update();
	auto exec_time = time.eval();
	auto elapsed_time = ((int) exec_time - timer.remaining_time());

	auto step =
			exec_time == 0.0 ?
					scaling_difference :
					scaling_difference * ((float) elapsed_time / exec_time);

	bullet.get_component<VelocityComponent>()->velocity = original_velocity
			* (1.0 + step);

	return timer.is_done();
}
