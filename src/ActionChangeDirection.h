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
#include "Direction.h"

class ActionChangeDirection: public Action {
private:
	Direction direction;
	Expression time;
	Timer timer;
	int last_time = 0;
	int elapsed_time = 0;
	float original_angle = 0;
	float direction_difference = 0;

public:
	ActionChangeDirection(Direction direction, Expression time) :
			Action(Action::CHANGE_DIRECTION), direction(direction), time(time) {
	}
	bool update(World& world, Entity& bullet, double dt);
	void set_repeat_to(int new_value) {
		direction.set_repeat_to(new_value);
		time.set_repeat_to(new_value);
	}
	ActionPtr clone() {
		return ActionPtr(new ActionChangeDirection(*this));
	}
};

#endif /* ACTIONCHANGEDIRECTION_H_ */
