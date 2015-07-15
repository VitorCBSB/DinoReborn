/*
 * PlayerAnimationManager.h
 *
 *  Created on: 07/01/2015
 *      Author: vitor
 */

#ifndef PLAYERANIMATIONMANAGER_H_
#define PLAYERANIMATIONMANAGER_H_

#include "../ecs/VECS.h"
#include "../events/PlayerMoveLeft.h"
#include "../events/PlayerMoveRight.h"
#include "../events/PlayerMoveForward.h"
#include "../events/PlayerMoveBackward.h"
#include "../events/PlayerStopLeft.h"
#include "../events/PlayerStopRight.h"
#include "../events/PlayerStopForward.h"
#include "../events/PlayerStopBackward.h"
#include "../components/AnimationComponent.h"
#include "../components/marker/PlayerMarker.h"
#include <array>

class PlayerAnimationManager: public SingleEntitySystem {
private:
	std::array<bool, 5> active_animations;

public:
	PlayerAnimationManager(WorldPtr world_ptr) :
			SingleEntitySystem(world_ptr) {
		active_animations[0] = true;
		for (unsigned int i = 1; i < active_animations.size(); i++) {
			active_animations[i] = false;
		}
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
		add_aspect(new AllOfAspect<PlayerMarker>());
	}

	void process_entity(Entity& entity, double dt);

	void handle(const PlayerMoveLeft& event);
	void handle(const PlayerMoveRight& event);
	void handle(const PlayerMoveForward& event);
	void handle(const PlayerMoveBackward& event);
	void handle(const PlayerStopLeft& event);
	void handle(const PlayerStopRight& event);
	void handle(const PlayerStopForward& event);
	void handle(const PlayerStopBackward& event);
};

#endif /* PLAYERANIMATIONMANAGER_H_ */
