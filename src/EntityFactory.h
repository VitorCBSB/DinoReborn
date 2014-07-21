/*
 * EntityFactory.h
 *
 *  Created on: 19/07/2014
 *      Author: vitor
 */

#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_

#include "ecs/VECS.h"
#include "components/PositionComponent.h"
#include "components/VelocityComponent.h"
#include "components/SpriteComponent.h"

class EntityFactory {
public:
	static EntityPtr create_background(World& world);
	static EntityPtr create_player(World& world);
	static EntityPtr create_bullet(World& world, PositionComponent* position);
};

#endif /* ENTITYFACTORY_H_ */
