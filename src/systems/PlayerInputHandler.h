/*
 * PlayerInputHandler.h
 *
 *  Created on: 17/07/2014
 *      Author: vitor
 */

#ifndef PLAYERINPUTHANDLER_H_
#define PLAYERINPUTHANDLER_H_

#include "../SDLBase.h"
#include "../EntityFactory.h"
#include "../ecs/VECS.h"
#include "../components/VelocityComponent.h"
#include "../events/PlayerMoveLeft.h"
#include "../events/PlayerMoveRight.h"
#include "../events/PlayerMoveForward.h"
#include "../events/PlayerMoveBackward.h"
#include "../events/PlayerStopLeft.h"
#include "../events/PlayerStopRight.h"
#include "../events/PlayerStopForward.h"
#include "../events/PlayerStopBackward.h"
#include "../events/PlayerShoot.h"
#include "../events/PlayerStopShooting.h"
#include "../Vector2.h"
#include "../GameAssets.h"

#define SPEED 200.0

class PlayerInputHandler: public System {
public:
	PlayerInputHandler(WorldPtr world_ptr) :
			System(world_ptr) {
		this->world_ptr.lock()->get_event_manager().subscribe<PlayerMoveLeft>(
				*this);
		this->world_ptr.lock()->get_event_manager().subscribe<PlayerMoveRight>(
				*this);
		this->world_ptr.lock()->get_event_manager().subscribe<PlayerMoveForward>(
				*this);
		this->world_ptr.lock()->get_event_manager().subscribe<PlayerMoveBackward>(
				*this);
		this->world_ptr.lock()->get_event_manager().subscribe<PlayerStopLeft>(
				*this);
		this->world_ptr.lock()->get_event_manager().subscribe<PlayerStopRight>(
				*this);
		this->world_ptr.lock()->get_event_manager().subscribe<PlayerStopForward>(
				*this);
		this->world_ptr.lock()->get_event_manager().subscribe<PlayerStopBackward>(
				*this);
		this->world_ptr.lock()->get_event_manager().subscribe<PlayerShoot>(
				*this);
		this->world_ptr.lock()->get_event_manager().subscribe<PlayerStopShooting>(
				*this);
	}

	void process_entities(double dt) {
	}

	void process_entity(Entity& entity, double dt) {
	}

	void handle(const PlayerMoveLeft& event);
	void handle(const PlayerMoveRight& event);
	void handle(const PlayerMoveForward& event);
	void handle(const PlayerMoveBackward& event);
	void handle(const PlayerStopLeft& event);
	void handle(const PlayerStopRight& event);
	void handle(const PlayerStopForward& event);
	void handle(const PlayerStopBackward& event);
	void handle(const PlayerShoot& event);
	void handle(const PlayerStopShooting& event);
};

#endif /* PLAYERINPUTHANDLER_H_ */
