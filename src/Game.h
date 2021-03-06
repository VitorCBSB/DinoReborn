/*
 * Game.h
 *
 *  Created on: 10/07/2014
 *      Author: vitor
 */

#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include <algorithm>
#include <memory>
#include "SDLBase.h"
#include "ecs/VECS.h"
#include "GameStates.h"
#include "EntityFactory.h"
#include "GameAssets.h"
#include "parser/BulletParser.h"
#include "systems/VelocitySystem.h"
#include "systems/BulletRemovalSystem.h"
#include "systems/CollisionSystem.h"
#include "systems/AnimationManagerSystem.h"
#include "systems/RenderingSystem.h"
#include "systems/RenderUISystem.h"
#include "systems/UpdateScreenSystem.h"
#include "systems/QuitSystem.h"
#include "systems/InputSystem.h"
#include "systems/PlayerInputHandler.h"
#include "systems/PlayerAnimationManager.h"
#include "systems/InputHandler.h"
#include "systems/ActionsSystem.h"
#include "systems/BulletRotationSystem.h"
#include "systems/ShotSystem.h"
#include "systems/OutOfBoundsSystem.h"
#include "systems/LoopingBackgroundSystem.h"

class Game {
private:
	WorldPtr world;

public:
	Game();
	virtual ~Game();

	void run();
	void initialize_sprites();
	void initialize_scripts();
};

#endif /* GAME_H_ */
