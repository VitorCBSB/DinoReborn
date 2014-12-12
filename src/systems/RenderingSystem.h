/*
 * RenderingSystem.h
 *
 *  Created on: 14/07/2014
 *      Author: vitor
 */

#ifndef RENDERINGSYSTEM_H_
#define RENDERINGSYSTEM_H_

#include <stdint.h>
#include <map>
#include <algorithm>
#include <functional>
#include "../ecs/VECS.h"
#include "../components/PositionComponent.h"
#include "../components/AnimationComponent.h"

class RenderingSystem: public System {
public:
	RenderingSystem(WorldPtr world_ptr);

	void process_entities(double dt);
	void process_entity(Entity& entity, double dt);
};

#endif /* RENDERINGSYSTEM_H_ */
