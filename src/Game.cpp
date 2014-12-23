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
	world->add_system<OutOfBoundsSystem>(world);
	world->add_system<ShotSystem>(world);
	world->add_system<ActionsSystem>(world);
	world->add_system<BulletRemovalSystem>(world);
	world->add_system<CollisionSystem>(world);
	world->add_system<AnimationManagerSystem>(world);
	world->add_system<BulletRotationSystem>(world);

	world->add_system<RenderingSystem>(world);
	world->add_system<RenderUISystem>(world);
	world->add_system<QuitSystem>(world);
	world->add_system<UpdateScreenSystem>(world);

	EntityFactory::create_player(*world);
	EntityFactory::create_background(*world);
	EntityFactory::create_test_entity(*world);
	EntityFactory::create_game_hud(*world);
	world->flush_changes();
}

void Game::initialize_scripts() {
	auto file_names = { "scripts/bullets/burst.xml",
			"scripts/bullets/tiro_simples.xml", "scripts/bullets/spread.xml" };

	for (auto& file_name : file_names) {
		GameData::scripts[file_name] = BulletParser(file_name).parse();
	}
}

void Game::initialize_sprites() {
	auto file_names = { "img/background.jpg", "img/PlayerSprite.png", "img/bullet.png",
			"img/MissileExplosion.png", "img/not_defined.png", "img/HUD.png" };

	for (auto& file_name : file_names) {
		GameData::sprites[file_name] = Sprite(file_name);
	}
}

Game::~Game() {
	SDLBase::finalize_SDL();
}

void Game::run() {
	int state = GameStates::STATE_NO_CHANGE;
	unsigned int elapsed_time;
	while (state == GameStates::STATE_NO_CHANGE) {
		auto base_time = SDL_GetTicks();
		state = world->process(0.016);
		elapsed_time = SDL_GetTicks() - base_time;
		SDL_Delay((unsigned int) std::max(0, 16 - (int) elapsed_time));
	}
}

