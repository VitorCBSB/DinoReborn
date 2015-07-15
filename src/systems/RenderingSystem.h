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
#include "../components/UIComponent.h"

class RenderingSystem: public SingleEntitySystem {
private:
	const int GAME_AREA_OFFSET = 200;

public:
	RenderingSystem(WorldPtr world_ptr);

	void sort_entities();
	void process_entity(Entity& entity, double dt);
};

#endif /* RENDERINGSYSTEM_H_ */
