/*
 * Game.cpp
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#include "Game.h"

Game::Game() {
	SDLBase::initialize_SDL();
	world.add_system(new VelocitySystem());
	world.add_system(new RenderingSystem());
	world.add_system(new QuitSystem());
	world.add_system(new UpdateScreenSystem());
}

Game::~Game() {
	SDLBase::finalize_SDL();
}

void Game::run() {
	auto& e = world.create_entity();
	e.add_component<PositionComponent>(100.0f, 100.0f);
	e.add_component<VelocityComponent>(50.0f, 0.0f);
	e.add_component<SpriteComponent>();

	while (true) {
		world.process(0.016);
		SDL_Delay(16);
	}
}

