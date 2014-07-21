/*
 * World.cpp
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#include "World.h"

EntityPtr World::create_entity() {
	auto e = EntityPtr(new Entity(new_entity_id++));
	entities[e->get_id()] = e;
	return e;
}

void World::remove_entity_from_everything(uint64_t id) {
	group_manager.remove_entity(id);
	entities.erase(id);
}

void World::remove_entity(uint64_t id) {
	remove_entity_from_everything(id);
}

void World::remove_entity(Entity& entity) {
	remove_entity_from_everything(entity.get_id());
}

int World::process(double dt) {
	for (auto& system : systems) {
		system->process_entities(entities, dt);
	}
	return next_state;
}
