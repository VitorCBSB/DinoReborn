/*
 * World.cpp
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#include "World.h"

World::World() {
}

World::~World() {
}

Entity& World::create_entity() {
	auto e = new Entity(new_entity_id++);
	entities[e->get_id()] = EntityPtr(e);
	return *entities[e->get_id()].get();
}

void World::add_system(System* system) {
	systems.push_back(SystemPtr(system));
}

void World::remove_entity(uint64_t id) {
	entities.erase(id);
}

void World::process(double dt) {
	for (auto& system : systems) {
		system->process_entities(entities, dt);
	}
}
