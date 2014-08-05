/*
 * ActionWait.cpp
 *
 *  Created on: 31/07/2014
 *      Author: vitor
 */

#include "ActionWait.h"

bool ActionWait::update(World& world, Entity& bullet, double dt) {
	if (!started) {
		started = true;
		timer.start((int) wait_time.eval());
	}
	timer.update();
	return timer.is_done();
}
