/*
 * MovingBackgroundSystem.cpp
 *
 *  Created on: 26/12/2014
 *      Author: vitor
 */

#include "LoopingBackgroundSystem.h"

// TODO - Remove magic numbers
void LoopingBackgroundSystem::process_entity(Entity& entity, double dt) {
	auto p = entity.get_component<PositionComponent>();

	if (p->position.y > 600 + 450) {
		p->position.y -= 2 * 900;
	}
}
