/*
 * VelocitySystem.cpp
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#include "VelocitySystem.h"

VelocitySystem::VelocitySystem(WorldPtr world_ptr) :
		System(world_ptr) {
	add_aspect(new AllOfAspect<PositionComponent, VelocityComponent>());
}

void VelocitySystem::process_entity(Entity& entity, double dt) {
	auto p = entity.get_component<PositionComponent>();
	auto v = entity.get_component<VelocityComponent>();

	p->position += v->velocity * dt;
}
