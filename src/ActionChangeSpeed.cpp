/*
 * ActionChangeSpeed.cpp
 *
 *  Created on: 01/08/2014
 *      Author: vitor
 */

#include "ActionChangeSpeed.h"

ActionChangeSpeed::ActionChangeSpeed(Expression target, Expression time,
		ChangeSpeedType type) :
		target(target), time(time), type(type) {
}

bool ActionChangeSpeed::update(World& world, Entity& bullet, double dt) {
	if (!started) {
		started = true;
		original_velocity = bullet.get_component<VelocityComponent>()->velocity;

		auto target_velocity =
				type == ABSOLUTE ?
						target.eval() :
						original_velocity.length() + target.eval();
		auto scaling = target_velocity / original_velocity.length();
		scaling_difference = scaling - 1.0;
		timer.start((int) time.eval());
	}
	timer.update();
	auto elapsed_time = ((int) time.eval() - timer.remaining_time());

	float step;
	if (time.eval() == 0.0) {
		step = scaling_difference;
	} else {
		step = scaling_difference * ((float) elapsed_time / time.eval());
	}
	bullet.get_component<VelocityComponent>()->velocity = original_velocity
			* (1.0 + step);

	return timer.is_done();
}
