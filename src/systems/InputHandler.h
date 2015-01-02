/*
 * InputHandler.h
 *
 *  Created on: 30/12/2014
 *      Author: vitor
 */

#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include "../ecs/VECS.h"
#include "../events/KeyboardDown.h"
#include "../events/KeyboardUp.h"
#include "../events/PlayerMoveForward.h"
#include "../events/PlayerMoveBackward.h"
#include "../events/PlayerMoveLeft.h"
#include "../events/PlayerMoveRight.h"
#include "../events/PlayerStopLeft.h"
#include "../events/PlayerStopRight.h"
#include "../events/PlayerStopForward.h"
#include "../events/PlayerStopBackward.h"
#include "../events/PlayerShoot.h"
#include "../events/PlayerStopShooting.h"

class InputHandler : public System {
public:
	InputHandler(WorldPtr world_ptr) : System(world_ptr) {
		world_ptr->get_event_manager().subscribe<KeyboardDown>(*this);
		world_ptr->get_event_manager().subscribe<KeyboardUp>(*this);
	}

	void process_entities(double dt) {
	}

	void process_entity(Entity& entity, double dt) {
	}

	void handle(const KeyboardDown& event);
	void handle(const KeyboardUp& event);
};

#endif /* INPUTHANDLER_H_ */
