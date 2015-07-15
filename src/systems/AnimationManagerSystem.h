/*
 * AnimationManagerSystem.h
 *
 *  Created on: 25/07/2014
 *      Author: vitor
 */

#ifndef ANIMATIONMANAGERSYSTEM_H_
#define ANIMATIONMANAGERSYSTEM_H_

#include "../ecs/VECS.h"
#include "../components/AnimationComponent.h"

class AnimationManagerSystem: public SingleEntitySystem {
public:
	AnimationManagerSystem(WorldPtr world_ptr) :
			SingleEntitySystem(world_ptr) {
		add_aspect(new AllOfAspect<AnimationComponent>());
	}

	void process_entity(Entity& entity, double dt);
};

#endif /* ANIMATIONMANAGERSYSTEM_H_ */
