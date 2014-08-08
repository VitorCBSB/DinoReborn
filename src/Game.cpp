/*
 * Game.cpp
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#include "Game.h"

Game::Game() :
		world(new World(GameStates::STATE_NO_CHANGE)) {
	SDLBase::initialize_SDL();

	initialize_sprites();
	initialize_scripts();

	world->add_system<InputSystem>(world);
	world->add_system<PlayerInputHandler>(world);
	world->add_system<VelocitySystem>(world);
	world->add_system<ActionsSystem>(world);
	world->add_system<BulletRemovalSystem>(world);
	world->add_system<CollisionSystem>(world);
	world->add_system<AnimationManagerSystem>(world);
	world->add_system<BulletRotationSystem>(world);
	world->add_system<RenderingSystem>(world);
	world->add_system<QuitSystem>(world);
	world->add_system<UpdateScreenSystem>(world);

	EntityFactory::create_player(*world);
	EntityFactory::create_background(*world);
	EntityFactory::create_test_entity(*world);
}

void Game::initialize_scripts() {
	GameData::scripts["scripts/bullets/burst.xml"] = BulletParser(
			"scripts/bullets/burst.xml").parse();
	GameData::scripts["scripts/bullets/tiro_simples.xml"] = BulletParser(
			"scripts/bullets/tiro_simples.xml").parse();
}

void Game::initialize_sprites() {
	GameData::sprites["img/background.jpg"] = Sprite("img/background.jpg");
	GameData::sprites["img/bullet.png"] = Sprite("img/bullet.png");
	GameData::sprites["img/MissileExplosion.png"] = Sprite(
			"img/MissileExplosion.png");
	GameData::sprites["img/not_defined.png"] = Sprite("img/not_defined.png");
}

Game::~Game() {
	SDLBase::finalize_SDL();
}

void Game::run() {
	while (world->process(0.016) == GameStates::STATE_NO_CHANGE) {
		SDL_Delay(16);
	}
}

