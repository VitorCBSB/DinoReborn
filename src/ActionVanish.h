/*
 * ActionVanish.h
 *
 *  Created on: 31/07/2014
 *      Author: vitor
 */

#ifndef ACTIONVANISH_H_
#define ACTIONVANISH_H_

#include "Action.h"

class ActionVanish: public Action {
public:
	bool update(World& world, Entity& bullet, double dt);
	void on_start() {
	}
	void increment_repeat() {
	}
};

#endif /* ACTIONVANISH_H_ */
