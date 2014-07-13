/*
 * VelocitySystem.cpp
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#include "VelocitySystem.h"

VelocitySystem::VelocitySystem() :
		System() {
	add_aspect(new AllOfAspect<PositionComponent, VelocityComponent>());
}

VelocitySystem::~VelocitySystem() {
}

void VelocitySystem::process_entity(Entity& entity) {
	auto p = entity.get_component<PositionComponent>();
	auto v = entity.get_component<VelocityComponent>();

	p->x += v->x;
	p->y += v->y;
}
