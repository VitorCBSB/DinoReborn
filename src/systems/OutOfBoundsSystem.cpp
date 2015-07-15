/*
 * OutOfBoundsSystem.cpp
 *
 *  Created on: 23/12/2014
 *      Author: vitor
 */

#include "OutOfBoundsSystem.h"

void OutOfBoundsSystem::process_entity(Entity& entity, double dt) {
	auto p = entity.get_component<PositionComponent>();

	// TODO - Remove magic numbers
	if (p->position.x < 0.0f) {
		p->position.x = 0.0f;
	} else if (p->position.x > 600.0f) {
		p->position.x = 600.0f;
	}

	if (p->position.y < 0.0f) {
		p->position.y = 0.0f;
	} else if (p->position.y > 600.0f) {
		p->position.y = 600.0f;
	}
}
