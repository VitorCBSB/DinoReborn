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
	player->assign_component<BoundingCircleComponent>(1.0f);

	world.get_tag_manager().set_entity_tag("player", player);

	return player;
}

EntityPtr EntityFactory::create_bullet(World& world,
		PositionComponent* position, VelocityComponent* velocity) {
	auto bullet = world.create_entity();

	bullet->assign_component(position);
	bullet->assign_component(velocity);
	bullet->assign_component<SpriteComponent>("img/bullet.png",
			atan2(velocity->velocity.y, velocity->velocity.x) * 180 / M_PI, 1);
	bullet->assign_component<BoundingCircleComponent>(1.0f);

	world.get_group_manager().assign_entity_to_group("bullets", bullet);

	return bullet;
}

EntityPtr EntityFactory::create_test_entity(World& world) {
	auto test = world.create_entity();

	test->assign_component<PositionComponent>(400, 150);
	test->assign_component<SpriteComponent>("img/not_defined.png", 0, 1);

	return test;
}
