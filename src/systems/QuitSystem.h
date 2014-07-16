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
#include <stdlib.h>

class QuitSystem: public System {
public:
	QuitSystem(std::shared_ptr<World> world_ptr) : System(world_ptr) {
		world_ptr->get_event_manager().subscribe<Quit>(*this);
	}

	void process_entities(std::map<uint64_t, EntityPtr>& entities, double dt) {
	}

	void process_entity(Entity& entity, double dt) {
	}

	void handle(const Quit& event) {
		exit(0);
	}
};

#endif /* QUITSYSTEM_H_ */
