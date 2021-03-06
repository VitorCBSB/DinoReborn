/*
 * EntityFactory.h
 *
 *  Created on: 19/07/2014
 *      Author: vitor
 */

#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_

#include <math.h>
#include "GameAssets.h"
#include "ecs/VECS.h"
#include "parser/BulletDefinition.h"
#include "components/ActionsComponent.h"
#include "components/PositionComponent.h"
#include "components/VelocityComponent.h"
#include "components/AnimationComponent.h"
#include "components/BoundingCircleComponent.h"
#include "components/ShotComponent.h"
#include "components/marker/UIComponent.h"
#include "components/marker/EnemyMarker.h"
#include "components/marker/BackgroundMarker.h"
#include "components/marker/BulletMarker.h"
#include "components/marker/PlayerMarker.h"

class EntityFactory {
public:
	static EntityPtr create_player(World& world);
	static EntityPtr create_bullet(World& world, PositionComponent* position,
			VelocityComponent* velocity, BulletDefinition bullet_definition);
	static EntityPtr create_test_entity(World& world);
	static EntityPtr create_explosion(World& world,
			PositionComponent* position);
	static EntityPtr create_game_hud(World& world);
	static void create_moving_backgrounds(World& world);
};

#endif /* ENTITYFACTORY_H_ */
