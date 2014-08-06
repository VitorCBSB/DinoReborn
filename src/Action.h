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
	Action() {
	}
	virtual ~Action() {
	}

	virtual bool update(World& world, Entity& bullet, double dt) = 0;
	virtual void increment_repeat() = 0;
	virtual std::unique_ptr<Action> clone() = 0;

	bool has_started() const {
		return started;
	}
	virtual void reset() {
		started = false;
	}
};

typedef std::unique_ptr<Action> ActionPtr;

#endif /* ACTION_H_ */
