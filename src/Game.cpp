/*
 * Game.cpp
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#include "Game.h"

Game::Game() {
	world.add_system(new VelocitySystem());
}

Game::~Game() {
}

void Game::run() {
	auto& e = world.create_entity();
	e.add_component<PositionComponent>(100.0f, 100.0f);
	e.add_component<VelocityComponent>(100.0f, 100.0f);

	world.process(0.016);

	auto p = e.get_component<PositionComponent>();
	printf("Pos: (%f, %f)\n", p->x, p->y);
}

int main() {
	Game game;
	game.run();
	return 0;
}
