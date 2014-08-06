/*
 * ActionChangeDirection.h
 *
 *  Created on: 04/08/2014
 *      Author: vitor
 */

#ifndef ACTIONCHANGEDIRECTION_H_
#define ACTIONCHANGEDIRECTION_H_

#include "ecs/VECS.h"
#include "Action.h"
#include "parser/Expression.h"
#include "Timer.h"
#include "components/VelocityComponent.h"

class ActionChangeDirection: public Action {
private:
	Expression direction;
	Expression time;
	Timer timer;
	int last_time = 0;
	int elapsed_time = 0;
	float original_angle = 0;
	float direction_difference = 0;

	float convert_to_minus_range(float angle);

public:
	ActionChangeDirection(Expression direction, Expression time) :
			direction(direction), time(time) {
	}
	bool update(World& world, Entity& bullet, double dt);
	void increment_repeat() {
		direction.increment_repeat();
		time.increment_repeat();
	}
	ActionPtr clone() {
		return ActionPtr(new ActionChangeDirection(*this));
	}
};

#endif /* ACTIONCHANGEDIRECTION_H_ */
