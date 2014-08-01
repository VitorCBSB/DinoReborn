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
	bool complete = false;

public:
	Action() {
	}
	virtual ~Action() {
	}

	virtual bool update(World& world, Entity& bullet, double dt) = 0;
	virtual void on_start() = 0;
	virtual void increment_repeat() = 0;
};

typedef std::unique_ptr<Action> ActionPtr;

#endif /* ACTION_H_ */
