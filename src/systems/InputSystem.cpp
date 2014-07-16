/*
 * InputSystem.cpp
 *
 *  Created on: 15/07/2014
 *      Author: vitor
 */

#include "InputSystem.h"

void InputSystem::process_entities(std::map<uint64_t, EntityPtr>& entities, double dt) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			world_ptr->get_event_manager().broadcast<Quit>();
			break;
		default:
			break;
		}
	}
}

void InputSystem::process_entity(Entity& entity, double dt) {
}
