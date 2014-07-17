/*
 * PlayerInputHandler.h
 *
 *  Created on: 17/07/2014
 *      Author: vitor
 */

#ifndef PLAYERINPUTHANDLER_H_
#define PLAYERINPUTHANDLER_H_

#include "../SDLBase.h"
#include "../ecs/VECS.h"
#include "../components/PlayerComponent.h"
#include "../components/VelocityComponent.h"
#include "../events/KeyboardDown.h"
#include "../events/KeyboardUp.h"
#include "../Vector2.h"

#define SPEED 50.0

class PlayerInputHandler : public System {
public:
	PlayerInputHandler(std::shared_ptr<World> world_ptr) : System(world_ptr) {
		world_ptr->get_event_manager().subscribe<KeyboardDown>(*this);
		world_ptr->get_event_manager().subscribe<KeyboardUp>(*this);
	}

	void process_entities(std::map<uint64_t, EntityPtr>& entities, double dt) {
	}

	void process_entity(Entity& entity, double dt) {
	}

	void handle(const KeyboardDown& event);
	void handle(const KeyboardUp& event);
};

#endif /* PLAYERINPUTHANDLER_H_ */
