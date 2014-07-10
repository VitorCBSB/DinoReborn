/*
 * Game.h
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include "ecs/Aspect.h"
#include "ecs/AndAspect.h"
#include "ecs/System.h"
#include "ecs/Entity.h"
#include "ecs/Component.h"

class Game {
public:
	Game();
	virtual ~Game();
};

#endif /* GAME_H_ */
