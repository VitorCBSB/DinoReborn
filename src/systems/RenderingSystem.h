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
#include "../components/SpriteComponent.h"

class RenderingSystem: public System {
public:
	RenderingSystem();

	void process_entities(std::map<uint64_t, EntityPtr>& entities, double dt);
	void process_entity(Entity& entity, double dt);
};

#endif /* RENDERINGSYSTEM_H_ */
