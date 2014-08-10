/*
 * ActionsSystem.cpp
 *
 *  Created on: 06/08/2014
 *      Author: vitor
 */

#include "ActionsSystem.h"

void ActionsSystem::process_entity(Entity& entity, double dt) {
	auto action_component = entity.get_component<ActionsComponent>();

	while (action_component->current_action != action_component->actions.end()) {
		if (!(*action_component->current_action)->update(*(world_ptr.lock()),
				entity, dt)) {
			return;
		}
		action_component->current_action++;
	}
}
