/*
 * EntityFactory.cpp
 *
 *  Created on: 19/07/2014
 *      Author: vitor
 */

#include "EntityFactory.h"

EntityPtr EntityFactory::create_player(World& world) {
	auto player = world.create_entity();

	world.assign_component<PositionComponent>(player, 300.0f, 500.0f);
	world.assign_component<VelocityComponent>(player, 0.0f, 0.0f);
	world.assign_component<AnimationComponent>(player,
			Animation(GameAssets::sprites["img/Player_sprites.png"], 88, 64,
					6, true, { 1, 1, 1, 1, 1 }), 3);
	world.assign_component<BoundingCircleComponent>(player, 1.0f);
	world.assign_component<ShotComponent>(player);
	world.assign_component<PlayerMarker>(player);

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
			Animation(GameAssets::sprites[bullet_definition.sprite_file_name],
					atan2(velocity->velocity.y, velocity->velocity.x)
							* 180.0/ M_PI), 2);
	world.assign_component<BoundingCircleComponent>(bullet, 1.0f);
	world.assign_component<ActionsComponent>(bullet, bullet_definition.actions);
	world.assign_component<BulletMarker>(bullet);

	return bullet;
}

EntityPtr EntityFactory::create_test_entity(World& world) {
	auto test = world.create_entity();

	world.assign_component<PositionComponent>(test, 400, 150);
	world.assign_component<AnimationComponent>(test,
			Animation(GameAssets::sprites["img/not_defined.png"]), 2);
	world.assign_component<BoundingCircleComponent>(test, 100.0f);
	world.assign_component<EnemyMarker>(test);

	return test;
}

EntityPtr EntityFactory::create_explosion(World& world,
		PositionComponent* position) {
	auto explosion = world.create_entity();

	world.assign_component(explosion, position);
	world.assign_component<AnimationComponent>(explosion,
			Animation(GameAssets::sprites["img/MissileExplosion.png"], 26, 27,
					6, false, { 4 }), 1);

	return explosion;
}

EntityPtr EntityFactory::create_game_hud(World& world) {
	auto hud = world.create_entity();

	world.assign_component<PositionComponent>(hud, 105, 300);
	world.assign_component<AnimationComponent>(hud,
			Animation(GameAssets::sprites["img/HUD.png"]), 0);
	world.assign_component<UIComponent>(hud);

	return hud;
}

// TODO - Remove magic numbers
void EntityFactory::create_moving_backgrounds(World& world) {
	auto bg1 = world.create_entity();
	world.assign_component<PositionComponent>(bg1, 300, 150);
	world.assign_component<VelocityComponent>(bg1, 0, 50);
	world.assign_component<AnimationComponent>(bg1,
			Animation(GameAssets::sprites["img/Dino BG1.png"]), 0);
	world.assign_component<BackgroundMarker>(bg1);

	auto bg2 = world.create_entity();
	world.assign_component<PositionComponent>(bg2, 300, -750);
	world.assign_component<VelocityComponent>(bg2, 0, 50);
	world.assign_component<AnimationComponent>(bg2,
			Animation(GameAssets::sprites["img/Dino BG1.png"]), 0);
	world.assign_component<BackgroundMarker>(bg2);
}
