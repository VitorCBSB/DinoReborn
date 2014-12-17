/*
 * EntityFactory.cpp
 *
 *  Created on: 19/07/2014
 *      Author: vitor
 */

#include "EntityFactory.h"

EntityPtr EntityFactory::create_background(World& world) {
	auto background = world.create_entity();

	world.assign_component<PositionComponent>(background, 400, 300);
	world.assign_component<AnimationComponent>(background,
			Animation(GameData::sprites["img/background.jpg"], true), 0);

	return background;
}

EntityPtr EntityFactory::create_player(World& world) {
	auto player = world.create_entity();

	world.assign_component<PositionComponent>(player, 100.0f, 100.0f);
	world.assign_component<VelocityComponent>(player, 0.0f, 0.0f);
	world.assign_component<AnimationComponent>(player,
			Animation(GameData::sprites["img/not_defined.png"], true), 3);
	world.assign_component<BoundingCircleComponent>(player, 1.0f);
	world.assign_component<ShotComponent>(player);

	world.get_tag_manager().set_entity_tag("player", player);

	return player;
}

EntityPtr EntityFactory::create_bullet(World& world,
		PositionComponent* position, VelocityComponent* velocity,
		BulletDefinition bullet_definition) {
	auto bullet = world.create_entity();

	world.assign_component(bullet, position);
	world.assign_component(bullet, velocity);
	world.assign_component<AnimationComponent>(bullet,
			Animation(GameData::sprites[bullet_definition.sprite_file_name],
					true,
					atan2(velocity->velocity.y, velocity->velocity.x)
							* 180.0/ M_PI), 2);
	world.assign_component<BoundingCircleComponent>(bullet, 1.0f);
	world.assign_component<ActionsComponent>(bullet, bullet_definition.actions);

	world.get_group_manager().assign_entity_to_group("bullets", bullet);

	return bullet;
}

EntityPtr EntityFactory::create_test_entity(World& world) {
	auto test = world.create_entity();

	world.assign_component<PositionComponent>(test, 400, 150);
	world.assign_component<AnimationComponent>(test,
			Animation(GameData::sprites["img/not_defined.png"], true), 2);
	world.assign_component<BoundingCircleComponent>(test, 100.0f);

	world.get_group_manager().assign_entity_to_group("enemies", test);

	return test;
}

EntityPtr EntityFactory::create_explosion(World& world,
		PositionComponent* position) {
	auto explosion = world.create_entity();

	world.assign_component(explosion, position);
	world.assign_component<AnimationComponent>(explosion,
			Animation(GameData::sprites["img/MissileExplosion.png"], 26, 27,
					100), 1);

	return explosion;
}
