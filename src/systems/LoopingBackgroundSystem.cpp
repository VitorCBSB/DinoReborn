/*
 * MovingBackgroundSystem.cpp
 *
 *  Created on: 26/12/2014
 *      Author: vitor
 */

#include "LoopingBackgroundSystem.h"

void LoopingBackgroundSystem::process_entities(double dt) {
	for (auto moving_background : world_ptr.lock()->get_group_manager().get_entities_from_group(
			"background")) {
		process_entity(*(moving_background.second), dt);
	}
}

// TODO - Remove magic numbers
void LoopingBackgroundSystem::process_entity(Entity& entity, double dt) {
	auto p = entity.get_component<PositionComponent>();

	if (p->position.y > 600 + 450) {
		p->position.y -= 2 * 900;
	}
}
