/*
 * CollisionSystem.h
 *
 *  Created on: 22/07/2014
 *      Author: vitor
 */

#ifndef COLLISIONSYSTEM_H_
#define COLLISIONSYSTEM_H_

#include "../ecs/VECS.h"
#include "../components/BoundingCircleComponent.h"
#include "../components/PositionComponent.h"
#include "../events/Collision.h"
#include <functional>

typedef std::function<void(EntityPtr a, EntityPtr b)> CollisionHandler;

class CollisionSystem: public System {
private:
	bool check_collision(Entity& a, Entity& b);
	void execute_collisions(EntityMap& a_map, EntityMap& b_map,
			CollisionHandler collision_handler);

public:
	CollisionSystem(WorldPtr world_ptr) :
			System(world_ptr) {
	}

	void process_entities(double dt);
	void process_entity(Entity& entity, double dt) {
	}
};

#endif /* COLLISIONSYSTEM_H_ */
