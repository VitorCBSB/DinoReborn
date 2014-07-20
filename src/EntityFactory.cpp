/*
 * EntityFactory.cpp
 *
 *  Created on: 19/07/2014
 *      Author: vitor
 */

#include "EntityFactory.h"

Entity& EntityFactory::create_background(World& world) {
	auto& background = world.create_entity();
	background.add_component<PositionComponent>(400, 300);
	background.add_component<SpriteComponent>("img/background.jpg", 0, 0);

	return background;
}

Entity& EntityFactory::create_player(World& world) {
	auto& player = world.create_entity();
	player.add_component<PositionComponent>(100.0f, 100.0f);
	player.add_component<VelocityComponent>(0.0f, 0.0f);
	player.add_component<SpriteComponent>("img/not_defined.png", 0, 1);
	player.add_component<PlayerComponent>();

	return player;
}
