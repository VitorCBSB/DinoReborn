/*
 * PlayerInputHandler.h
 *
 *  Created on: 17/07/2014
 *      Author: vitor
 */

#ifndef PLAYERINPUTHANDLER_H_
#define PLAYERINPUTHANDLER_H_

#include "../SDLBase.h"
#include "../EntityFactory.h"
#include "../ecs/VECS.h"
#include "../components/VelocityComponent.h"
#include "../events/KeyboardDown.h"
#include "../events/KeyboardUp.h"
#include "../Vector2.h"
#include "../GameAssets.h"

#define SPEED 200.0

class PlayerInputHandler: public System {
public:
	PlayerInputHandler(WorldPtr world_ptr) :
			System(world_ptr) {
		this->world_ptr.lock()->get_event_manager().subscribe<KeyboardDown>(
				*this);
		this->world_ptr.lock()->get_event_manager().subscribe<KeyboardUp>(
				*this);
	}

	void process_entities(double dt) {
	}

	void process_entity(Entity& entity, double dt) {
	}

	void handle(const KeyboardDown& event);
	void handle(const KeyboardUp& event);
};

#endif /* PLAYERINPUTHANDLER_H_ */
