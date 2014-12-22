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
#include "../events/PlayerBulletEnemyCollision.h"
#include <functional>

typedef std::function<void(EntityPtr a, EntityPtr b)> CollisionHandler;

class CollisionSystem: public System {
private:
	bool check_collision(Entity& a, Entity& b);

	template <typename CollisionType>
	void execute_collisions(EntityMap& a_map, EntityMap& b_map) {
		for (auto a_it = a_map.begin(); a_it != a_map.end(); a_it++) {
			auto a = a_it->second;
			for (auto b_it = b_map.begin(); b_it != b_map.end(); b_it++) {
				auto b = b_it->second;
				if (check_collision(*a, *b)) {
					world_ptr.lock()->get_event_manager().broadcast<CollisionType>(
							a, b);
				}
			}
		}

	}

public:
	CollisionSystem(WorldPtr world_ptr) :
			System(world_ptr) {
	}

	void process_entities(double dt);
	void process_entity(Entity& entity, double dt) {
	}
};

#endif /* COLLISIONSYSTEM_H_ */
