/*
 * EntityFactory.h
 *
 *  Created on: 19/07/2014
 *      Author: vitor
 */

#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_

#include "ecs/VECS.h"
#include "components/PlayerComponent.h"
#include "components/PositionComponent.h"
#include "components/VelocityComponent.h"
#include "components/SpriteComponent.h"

class EntityFactory {
public:
	static Entity& create_background(World& world);
	static Entity& create_player(World& world);
};

#endif /* ENTITYFACTORY_H_ */
