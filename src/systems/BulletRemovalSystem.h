/*
 * BulletRemovalSystem.h
 *
 *  Created on: 23/07/2014
 *      Author: vitor
 */

#ifndef BULLETREMOVALSYSTEM_H_
#define BULLETREMOVALSYSTEM_H_

#include "../ecs/VECS.h"
#include "../events/Collision.h"
#include "../components/PositionComponent.h"

class BulletRemovalSystem: public System {
public:
	BulletRemovalSystem(WorldPtr world_ptr) :
			System(world_ptr) {
		this->world_ptr.lock()->get_event_manager().subscribe<Collision>(*this);
	}

	void process_entities(std::map<uint64_t, EntityPtr>& entities, double dt);
	void process_entity(Entity& entity, double dt);

	void handle(const Collision& event);
};

#endif /* BULLETREMOVALSYSTEM_H_ */
