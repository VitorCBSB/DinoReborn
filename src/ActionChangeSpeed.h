/*
 * ActionChangeSpeed.h
 *
 *  Created on: 01/08/2014
 *      Author: vitor
 */

#ifndef ACTIONCHANGESPEED_H_
#define ACTIONCHANGESPEED_H_

#include "Action.h"
#include "ecs/VECS.h"
#include "Timer.h"
#include "parser/Expression.h"
#include "components/VelocityComponent.h"
#include "Vector2.h"
#include <stdio.h>
#include <stdlib.h>

class ActionChangeSpeed: public Action {
private:
	Expression speed;
	Expression time;
	Timer timer;
	Vector2 original_velocity;
	float scaling_difference = 0;

public:
	enum ChangeSpeedType {
		ABSOLUTE, RELATIVE
	};

	ActionChangeSpeed(Expression speed, Expression time, ChangeSpeedType type);

	void increment_repeat() {
		time.increment_repeat();
		speed.increment_repeat();
	}
	void reset_repeat() {
		time.reset_repeat();
		speed.reset_repeat();
	}
	bool update(World& world, Entity& bullet, double dt);
	ActionPtr clone() {
		return ActionPtr(new ActionChangeSpeed(*this));
	}

private:
	ChangeSpeedType type;
};

#endif /* ACTIONCHANGESPEED_H_ */
