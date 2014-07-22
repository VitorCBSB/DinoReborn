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

class QuitSystem: public System {
public:
	QuitSystem(WorldPtr world_ptr) :
			System(world_ptr) {
		this->world_ptr.lock()->get_event_manager().subscribe<Quit>(*this);
	}

	void process_entities(std::map<uint64_t, EntityPtr>& entities, double dt) {
	}

	void process_entity(Entity& entity, double dt) {
	}

	void handle(const Quit& event) {
		world_ptr.lock()->next_state = GameStates::STATE_QUIT;
	}
};

#endif /* QUITSYSTEM_H_ */
