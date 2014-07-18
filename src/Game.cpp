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
}

Game::~Game() {
	SDLBase::finalize_SDL();
}

void Game::run() {
	auto& e = world->create_entity();
	e.add_component<PositionComponent>(100.0f, 100.0f);
	e.add_component<VelocityComponent>(0.0f, 0.0f);
	e.add_component<SpriteComponent>("img/not_defined.png", 1);
	e.add_component<PlayerComponent>();

	auto& bg = world->create_entity();
	bg.add_component<PositionComponent>(400, 300);
	bg.add_component<SpriteComponent>("img/background.jpg", 0);

	while (true) {
		world->process(0.016);
		SDL_Delay(16);
	}
}

