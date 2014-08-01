/*
 * ActionWait.cpp
 *
 *  Created on: 31/07/2014
 *      Author: vitor
 */

#include "ActionWait.h"

void ActionWait::on_start() {
	timer.start((int) wait_time.eval());
}

bool ActionWait::update(World& world, Entity& bullet, double dt) {
	timer.update();
	return timer.is_done();
}
