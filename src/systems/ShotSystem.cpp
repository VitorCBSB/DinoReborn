/*
 * ShotSystem.cpp
 *
 *  Created on: 17/12/2014
 *      Author: vitor
 */

#include "ShotSystem.h"

void ShotSystem::process_entity(Entity& entity, double dt) {
	auto shot_component = entity.get_component<ShotComponent>();

	shot_component->shot_cooldown.update();
	if (shot_component->shooting && shot_component->shot_cooldown.is_done()) {
		shot_component->shot_cooldown.start(SHOT_COOLDOWN_TIMER);
		auto position = entity.get_component<PositionComponent>();

		auto bullet = EntityFactory::create_bullet(*(world_ptr.lock()),
				new PositionComponent(*position),
				new VelocityComponent(0, -300),
				GameAssets::scripts[shot_component->shot_script]);
		world_ptr.lock()->assign_component<PlayerBulletMarker>(bullet);
	}
}

