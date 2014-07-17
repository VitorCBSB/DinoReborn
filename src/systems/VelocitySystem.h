/*
 * VelocitySystem.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef VELOCITYSYSTEM_H_
#define VELOCITYSYSTEM_H_

#include "../ecs/VECS.h"
#include "../components/PositionComponent.h"
#include "../components/VelocityComponent.h"

class VelocitySystem: public System {
public:
	VelocitySystem(std::shared_ptr<World> world_ptr);

	void process_entity(Entity& entity, double dt);

};

#endif /* VELOCITYSYSTEM_H_ */