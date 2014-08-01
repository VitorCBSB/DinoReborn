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
	int current_iteration = 0;
	int times;
	bool started = false;

public:
	ActionRepeat(std::vector<ActionPtr>& actions, int times);

	bool update(World& world, Entity& bullet, double dt);
	void increment_repeat() {
		current_iteration++;
		for (auto& action : actions) {
			action->increment_repeat();
		}
	}
	void on_start() {
	}
};

#endif /* ACTIONREPEAT_H_ */
