/*
 * InputSystem.h
 *
 *  Created on: 15/07/2014
 *      Author: vitor
 */

#ifndef INPUTSYSTEM_H_
#define INPUTSYSTEM_H_

#include "../ecs/VECS.h"
#include "../SDLBase.h"
#include "../events/Quit.h"
#include "../events/KeyboardDown.h"
#include "../events/KeyboardUp.h"
#include <map>
#include <stdint.h>

class InputSystem: public System {
public:
	InputSystem(WorldPtr world_ptr) :
			System(world_ptr) {
	}
	void process_entities(double dt);
	void process_entity(Entity& entity, double dt);
};

#endif /* INPUTSYSTEM_H_ */
