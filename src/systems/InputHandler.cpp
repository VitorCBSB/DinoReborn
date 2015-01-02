/*
 * InputHandler.cpp
 *
 *  Created on: 30/12/2014
 *      Author: vitor
 */

#include "InputHandler.h"

void InputHandler::handle(const KeyboardDown& event) {
	switch (event.key) {
	case SDL_SCANCODE_LEFT:
		world_ptr.lock()->get_event_manager().broadcast<PlayerMoveLeft>();
		break;
	case SDL_SCANCODE_RIGHT:
		world_ptr.lock()->get_event_manager().broadcast<PlayerMoveRight>();
		break;
	case SDL_SCANCODE_UP:
		world_ptr.lock()->get_event_manager().broadcast<PlayerMoveForward>();
		break;
	case SDL_SCANCODE_DOWN:
		world_ptr.lock()->get_event_manager().broadcast<PlayerMoveBackward>();
		break;
	case SDL_SCANCODE_Z:
		world_ptr.lock()->get_event_manager().broadcast<PlayerShoot>();
		break;
	default:
		break;
	}
}

void InputHandler::handle(const KeyboardUp& event) {
	switch(event.key) {
	case SDL_SCANCODE_LEFT:
		world_ptr.lock()->get_event_manager().broadcast<PlayerStopLeft>();
		break;
	case SDL_SCANCODE_RIGHT:
		world_ptr.lock()->get_event_manager().broadcast<PlayerStopRight>();
		break;
	case SDL_SCANCODE_UP:
		world_ptr.lock()->get_event_manager().broadcast<PlayerStopForward>();
		break;
	case SDL_SCANCODE_DOWN:
		world_ptr.lock()->get_event_manager().broadcast<PlayerStopBackward>();
		break;
	case SDL_SCANCODE_Z:
		world_ptr.lock()->get_event_manager().broadcast<PlayerStopShooting>();
		break;
	default:
		break;
	}
}
