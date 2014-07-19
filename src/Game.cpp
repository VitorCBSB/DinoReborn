/*
 * Game.cpp
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#include "Game.h"

Game::Game() :
		world(new World()) {
	SDLBase::initialize_SDL();
	world->add_system<InputSystem>(world);
	world->add_system<PlayerInputHandler>(world);
	world->add_system<VelocitySystem>(world);
	world->add_system<RenderingSystem>(world);
	world->add_system<QuitSystem>(world);
	world->add_system<UpdateScreenSystem>(world);

	EntityFactory::create_player(*world);
	EntityFactory::create_background(*world);
}

Game::~Game() {
	SDLBase::finalize_SDL();
}

void Game::run() {
	while (true) {
		world->process(0.016);
		SDL_Delay(16);
	}
}

