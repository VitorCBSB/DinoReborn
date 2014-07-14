/*
 * Game.h
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include "SDLBase.h"
#include "ecs/VECS.h"
#include "systems/VelocitySystem.h"
#include "systems/RenderingSystem.h"
#include "systems/UpdateScreenSystem.h"
#include "systems/QuitSystem.h"
#include "components/PositionComponent.h"
#include "components/VelocityComponent.h"
#include "components/SpriteComponent.h"

class Game {
private:
	World world;

public:
	Game();
	virtual ~Game();

	void run();
};

#endif /* GAME_H_ */
