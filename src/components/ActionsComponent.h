/*
 * ActionsComponent.h
 *
 *  Created on: 06/08/2014
 *      Author: vitor
 */

#ifndef ACTIONSCOMPONENT_H_
#define ACTIONSCOMPONENT_H_

#include "../ecs/VECS.h"
#include "../Action.h"
#include <vector>

class ActionsComponent: public Component<ActionsComponent> {
public:
	std::vector<ActionPtr> actions;
	std::vector<ActionPtr>::iterator current_action;

	ActionsComponent();
	ActionsComponent(std::vector<ActionPtr>& actions) {
		for (auto& action : actions) {
			this->actions.push_back(action->clone());
		}
		current_action = this->actions.begin();
	}
};

#endif /* ACTIONSCOMPONENT_H_ */
