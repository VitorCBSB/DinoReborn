/*
 * UpdateScreenSystem.h
 *
 *  Created on: 14/07/2014
 *      Author: vitor
 */

#ifndef UPDATESCREENSYSTEM_H_
#define UPDATESCREENSYSTEM_H_

#include "../ecs/VECS.h"
#include "../SDLBase.h"

class UpdateScreenSystem: public IndependentSystem {
public:
	UpdateScreenSystem(WorldPtr world_ptr) :
			IndependentSystem(world_ptr) {
	}

	void process(double dt) {
		SDLBase::update_screen();
		SDLBase::clear_screen();
	}
};

#endif /* UPDATESCREENSYSTEM_H_ */
