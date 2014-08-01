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
	do {
		if (!started) {
			started = true;
			for (auto& action : actions) {
				action->on_start();
			}
		}

		for (auto it = actions.begin(); it != actions.end(); it++) {
			if (!(*it)->update(world, bullet, dt)) {
				return false;
			}
		}

		if (current_iteration < times) {
			increment_repeat();
			started = false;
		}
	} while (current_iteration < times);

	return true;
}

