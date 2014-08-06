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
	void increment_repeat() {
	}
	ActionPtr clone() {
		return ActionPtr(new ActionVanish(*this));
	}
};

#endif /* ACTIONVANISH_H_ */
