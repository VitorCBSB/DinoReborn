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

class UpdateScreenSystem: public System {
public:
	UpdateScreenSystem(std::shared_ptr<World> world_ptr) :
			System(world_ptr) {
	}

	void process_entities(std::map<uint64_t, EntityPtr>& entities, double dt) {
		SDLBase::update_screen();
		SDLBase::clear_screen();
	}

	void process_entity(Entity& entity, double dt) {
	}
};

#endif /* UPDATESCREENSYSTEM_H_ */