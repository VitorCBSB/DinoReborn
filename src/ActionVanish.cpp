/*
 * ActionVanish.cpp
 *
 *  Created on: 31/07/2014
 *      Author: vitor
 */

#include "ActionVanish.h"

bool ActionVanish::update(World& world, Entity& entity, double dt) {
	world.remove_entity(entity.get_id());
	return false;
}
