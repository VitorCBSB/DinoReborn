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

// This class should not implement any of its inherited methods
// It is replaced at script compile time (in the semantic analysis phase)
// by its vector of actions times the number of times
// they're supposed to be executed.

class ActionRepeat: public Action {
public:
	std::vector<ActionPtr> actions;
	int times;

	ActionRepeat(const ActionRepeat& other) : Action(Action::REPEAT) {
		times = other.times;
		for (auto& action : actions) {
			this->actions.emplace_back(action->clone());
		}
	}
	ActionRepeat& operator=(const ActionRepeat& other) {
		tag = other.tag;
		times = other.times;
		for (auto& action : actions) {
			this->actions.emplace_back(action->clone());
		}
		return *this;
	}
	ActionRepeat(const std::vector<ActionPtr>& actions, int times)
		: Action(Action::REPEAT), times(times) {
		for (auto& action : actions) {
			this->actions.emplace_back(action->clone());
		}
	}

	bool update(World& world, Entity& bullet, double dt) {
		return false;
	}
	void set_repeat_to(int new_value) {
	}
	ActionPtr clone() {
		return ActionPtr(new ActionRepeat(*this));
	}
};

#endif /* ACTIONREPEAT_H_ */
