/*
 * RenderUISystem.h
 *
 *  Created on: 23/12/2014
 *      Author: vitor
 */

#ifndef RENDERUISYSTEM_H_
#define RENDERUISYSTEM_H_

#include <vector>
#include <algorithm>
#include "../ecs/VECS.h"
#include "../components/PositionComponent.h"
#include "../components/marker/UIComponent.h"
#include "../components/AnimationComponent.h"

class RenderUISystem: public SingleEntitySystem {
public:
	RenderUISystem(WorldPtr world_ptr);

	void process_entity(Entity& entity, double dt);
};

#endif /* RENDERUISYSTEM_H_ */
