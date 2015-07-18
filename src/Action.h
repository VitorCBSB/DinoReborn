/*
 * Action.h
 *
 *  Created on: 31/07/2014
 *      Author: vitor
 */

#ifndef ACTION_H_
#define ACTION_H_

#include "ecs/VECS.h"
#include <memory>

class Action {
protected:
	bool started = false;

public:
	enum ActionType {
		CHANGE_DIRECTION,
		CHANGE_SPEED,
		FIRE,
		REPEAT,
		VANISH,
		WAIT
	};

	Action(ActionType tag) : tag(tag) {
	}
	virtual ~Action() {
	}

	virtual bool update(World& world, Entity& bullet, double dt) = 0;
	virtual void set_repeat_to(int new_value) = 0;
	virtual std::unique_ptr<Action> clone() = 0;

	bool has_started() const {
		return started;
	}

	ActionType tag;
};

typedef std::unique_ptr<Action> ActionPtr;

#endif /* ACTION_H_ */
