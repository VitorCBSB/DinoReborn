/*
 * RenderingSystem.cpp
 *
 *  Created on: 14/07/2014
 *      Author: vitor
 */

#include "RenderingSystem.h"

RenderingSystem::RenderingSystem() {
	add_aspect(new AllOfAspect<PositionComponent, SpriteComponent>());
}

bool compare_priorities(Entity& e1, Entity& e2) {
	auto p1 = e1.get_component<SpriteComponent>()->priority;
	auto p2 = e2.get_component<SpriteComponent>()->priority;
	return p1 < p2;
}

void RenderingSystem::process_entities(std::map<uint64_t, EntityPtr>& entities,
		double dt) {
	std::vector<std::reference_wrapper<Entity>> ordered_entities;
	for (auto& entity_entry : entities) {
		if (validate(*(entity_entry.second))) {
			ordered_entities.push_back(*(entity_entry.second));
		}
	}

	std::sort(ordered_entities.begin(), ordered_entities.end(),
			compare_priorities);

	for (auto& entity : ordered_entities) {
		process_entity(entity, dt);
	}
}

void RenderingSystem::process_entity(Entity& entity, double dt) {
	auto s = entity.get_component<SpriteComponent>();
	auto p = entity.get_component<PositionComponent>();
	s->sprite.render(p->position.x, p->position.y);
}
