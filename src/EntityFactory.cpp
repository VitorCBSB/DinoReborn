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
	background->assign_component<AnimationComponent>(
			Animation(GameData::sprites["img/background.jpg"], true), 0);

	return background;
}

EntityPtr EntityFactory::create_player(World& world) {
	auto player = world.create_entity();

	player->assign_component<PositionComponent>(100.0f, 100.0f);
	player->assign_component<VelocityComponent>(0.0f, 0.0f);
	player->assign_component<AnimationComponent>(
			Animation(GameData::sprites["img/not_defined.png"], true), 3);
	player->assign_component<BoundingCircleComponent>(1.0f);

	world.get_tag_manager().set_entity_tag("player", player);

	return player;
}

EntityPtr EntityFactory::create_bullet(World& world,
		PositionComponent* position, VelocityComponent* velocity,
		BulletDefinition bullet_definition) {
	auto bullet = world.create_entity();

	bullet->assign_component(position);
	bullet->assign_component(velocity);
	bullet->assign_component<AnimationComponent>(
			Animation(GameData::sprites[bullet_definition.sprite_file_name],
					true,
					atan2(velocity->velocity.y, velocity->velocity.x)
							* 180.0/ M_PI), 2);
	bullet->assign_component<BoundingCircleComponent>(1.0f);
	bullet->assign_component<ActionsComponent>(bullet_definition.actions);

	world.get_group_manager().assign_entity_to_group("bullets", bullet);

	return bullet;
}

EntityPtr EntityFactory::create_test_entity(World& world) {
	auto test = world.create_entity();

	test->assign_component<PositionComponent>(400, 150);
	test->assign_component<AnimationComponent>(
			Animation(GameData::sprites["img/not_defined.png"], true), 2);
	test->assign_component<BoundingCircleComponent>(100.0f);

	world.get_group_manager().assign_entity_to_group("enemies", test);

	return test;
}

EntityPtr EntityFactory::create_explosion(World& world,
		PositionComponent* position) {
	auto explosion = world.create_entity();

	explosion->assign_component(position);
	explosion->assign_component<AnimationComponent>(
			Animation(GameData::sprites["img/MissileExplosion.png"], 26, 27,
					100), 1);

	return explosion;
}
