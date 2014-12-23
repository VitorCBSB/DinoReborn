/*
 * RenderUISystem.cpp
 *
 *  Created on: 23/12/2014
 *      Author: vitor
 */

#include "RenderUISystem.h"

void RenderUISystem::process_entities(double dt) {
	std::vector<std::reference_wrapper<Entity>> ordered_entities;
	for (auto& entity_entry : valid_entities) {
		ordered_entities.push_back(*(entity_entry.second));
	}

	std::sort(ordered_entities.begin(), ordered_entities.end(),
			[&](Entity& e1, Entity& e2) {
				auto p1 = e1.get_component<AnimationComponent>()->priority;
				auto p2 = e2.get_component<AnimationComponent>()->priority;
				return p1 < p2;
			});

	for (auto& entity : ordered_entities) {
		process_entity(entity, dt);
	}
}

void RenderUISystem::process_entity(Entity& entity, double dt) {
	auto s = entity.get_component<AnimationComponent>();
	auto p = entity.get_component<PositionComponent>();
	s->animation.clip_sprite();
	s->animation.render(p->position.x, p->position.y);
}
