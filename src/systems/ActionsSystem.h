/*
 * ActionsSystem.h
 *
 *  Created on: 06/08/2014
 *      Author: vitor
 */

#ifndef ACTIONSSYSTEM_H_
#define ACTIONSSYSTEM_H_

#include "../ecs/VECS.h"
#include "../components/ActionsComponent.h"

class ActionsSystem: public SingleEntitySystem {
public:
	ActionsSystem(WorldPtr world_ptr) :
			System(world_ptr) {
		add_aspect(new AllOfAspect<ActionsComponent>());
	}
	void process_entity(Entity& entity, double dt);
};

#endif /* ACTIONSSYSTEM_H_ */
