/*
 * ActionWait.h
 *
 *  Created on: 31/07/2014
 *      Author: vitor
 */

#ifndef ACTIONWAIT_H_
#define ACTIONWAIT_H_

#include "Action.h"
#include "Timer.h"
#include "parser/Expression.h"

class ActionWait: public Action {
private:
	Timer timer;
	Expression wait_time;

public:
	ActionWait(Expression wait_time_ms) :
			Action(Action::WAIT), wait_time(wait_time_ms) {
	}

	bool update(World& world, Entity& bullet, double dt);
	void set_repeat_to(int new_value) {
		wait_time.set_repeat_to(new_value);
	}
	ActionPtr clone() {
		return ActionPtr(new ActionWait(*this));
	}
};

#endif /* ACTIONWAIT_H_ */
