/*
 * Game.h
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include <memory>
#include "SDLBase.h"
#include "ecs/VECS.h"
#include "GameStates.h"
#include "EntityFactory.h"
#include "systems/VelocitySystem.h"
#include "systems/RenderingSystem.h"
#include "systems/UpdateScreenSystem.h"
#include "systems/QuitSystem.h"
#include "systems/InputSystem.h"
#include "systems/PlayerInputHandler.h"

class Game {
private:
	WorldPtr world;

public:
	Game();
	virtual ~Game();

	void run();
};

#endif /* GAME_H_ */
