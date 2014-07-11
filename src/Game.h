/*
 * Game.h
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include "ecs/Aspect.h"
#include "ecs/AllOfAspect.h"
#include "ecs/OneOfAspect.h"
#include "ecs/ExcludeAspect.h"
#include "ecs/System.h"
#include "ecs/Entity.h"
#include "ecs/Component.h"
#include "ecs/World.h"
#include "systems/VelocitySystem.h"
#include "components/PositionComponent.h"
#include "components/VelocityComponent.h"

class Game {
private:
	World world;

public:
	Game();
	virtual ~Game();

	void run();
};

#endif /* GAME_H_ */
