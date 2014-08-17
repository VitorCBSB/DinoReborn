/*
 * ActionRepeat.h
 *
 *  Created on: 01/08/2014
 *      Author: vitor
 */

#ifndef ACTIONREPEAT_H_
#define ACTIONREPEAT_H_

#include "Action.h"
#include <vector>

class ActionRepeat: public Action {
private:
	std::vector<ActionPtr> actions;
	std::vector<ActionPtr>::iterator current_action;
	int current_iteration = 0;
	int times;

public:
	ActionRepeat(std::vector<ActionPtr>& actions, int times);
	ActionRepeat(const ActionRepeat& other) {
		for (auto& action : other.actions) {
			actions.push_back(action->clone());
		}
		current_iteration = other.current_iteration;
		times = other.times;
	}

	bool update(World& world, Entity& bullet, double dt);
	void increment_repeat() {
		current_iteration++;
		for (auto& action : actions) {
			action->increment_repeat();
		}
	}
	void reset_repeat() {
	}
	void reset() {
		started = false;
		current_iteration = 0;
		for (auto& action : actions) {
			action->reset_repeat();
		}
	}
	ActionPtr clone() {
		return ActionPtr(new ActionRepeat(*this));
	}
};

#endif /* ACTIONREPEAT_H_ */
