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
	changed_entities[e->id] = e;
	return e;
}

void World::remove_entity_from_everything(uint64_t id) {
	tag_manager.remove_entity(entities[id]->get_tag());
	entities.erase(id);

	for (auto& system : systems) {
		system->remove_entity(id);
	}
}

void World::remove_entity(uint64_t id) {
	removed_entities[id] = entities[id];
}

void World::remove_entity(EntityPtr entity) {
	removed_entities[entity->id] = entity;
}

int World::process(double dt) {
	for (auto& system : systems) {
		system->process(dt);
		flush_changes();
	}
	return next_state;
}

void World::flush_changes() {
	for (auto& changed_entity : changed_entities) {
		for (auto& system : systems) {
			system->update_entity(changed_entity.second);
		}
	}

	for (auto& removed_entity : removed_entities) {
		remove_entity_from_everything(removed_entity.second->id);
	}

	changed_entities.clear();
	removed_entities.clear();
}

