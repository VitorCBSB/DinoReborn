/*
 * QuitSystem.h
 *
 *  Created on: 14/07/2014
 *      Author: vitor
 */

#ifndef QUITSYSTEM_H_
#define QUITSYSTEM_H_

#include "../ecs/VECS.h"
#include "../SDLBase.h"
#include "../events/Quit.h"
#include "../GameStates.h"
#include <stdlib.h>

class QuitSystem: public IndependentSystem {
public:
	QuitSystem(WorldPtr world_ptr) :
			IndependentSystem(world_ptr) {
		this->world_ptr.lock()->get_event_manager().subscribe<Quit>(*this);
	}

	void process(double dt) {
	}

	void handle(const Quit& event) {
		world_ptr.lock()->next_state = GameStates::STATE_QUIT;
	}
};

#endif /* QUITSYSTEM_H_ */
