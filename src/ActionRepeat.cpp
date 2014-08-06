/*
 * ActionRepeat.cpp
 *
 *  Created on: 01/08/2014
 *      Author: vitor
 */

#include "ActionRepeat.h"

ActionRepeat::ActionRepeat(std::vector<ActionPtr>& actions, int times) :
		times(times) {
	for (auto it = actions.begin(); it != actions.end(); it++) {
		this->actions.push_back(std::move(*it));
	}
	actions.clear();
}

bool ActionRepeat::update(World& world, Entity& bullet, double dt) {
	while (current_iteration < times) {
		if (!started) {
			started = true;
			current_action = actions.begin();
			for (auto& action : actions) {
				action->reset();
			}
		}

		for (; current_action != actions.end(); current_action++) {
			if (!(*current_action)->update(world, bullet, dt)) {
				return false;
			}
		}

		increment_repeat();
		started = false;
	}

	return true;
}

