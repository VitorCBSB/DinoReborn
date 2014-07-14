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
#include <stdlib.h>

class QuitSystem: public System {
public:
	QuitSystem() {
	}

	void process_entities(std::map<uint64_t, EntityPtr>& entities, double dt) {
		if (SDL_QuitRequested()) {
			exit(0);
		}
	}

	void process_entity(Entity& entity, double dt) {
	}
};

#endif /* QUITSYSTEM_H_ */
