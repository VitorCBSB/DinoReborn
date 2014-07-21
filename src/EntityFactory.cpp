/*
 * EntityFactory.cpp
 *
 *  Created on: 19/07/2014
 *      Author: vitor
 */

#include "EntityFactory.h"

EntityPtr EntityFactory::create_background(World& world) {
	auto background = world.create_entity();

	background->assign_component<PositionComponent>(400, 300);
	background->assign_component<SpriteComponent>("img/background.jpg", 0, 0);

	return background;
}

EntityPtr EntityFactory::create_player(World& world) {
	auto player = world.create_entity();

	player->assign_component<PositionComponent>(100.0f, 100.0f);
	player->assign_component<VelocityComponent>(0.0f, 0.0f);
	player->assign_component<SpriteComponent>("img/not_defined.png", 0, 2);

	world.get_tag_manager().set_entity_tag("player", player);

	return player;
}

EntityPtr EntityFactory::create_bullet(World& world, PositionComponent* position) {
	auto bullet = world.create_entity();

	bullet->assign_component(position);
	bullet->assign_component<VelocityComponent>(0, -300);
	bullet->assign_component<SpriteComponent>("img/bullet.png", -90, 1);

	world.get_group_manager().assign_entity_to_group("bullets", bullet);

	return bullet;
}
