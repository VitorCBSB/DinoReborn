/*
 * VelocitySystem.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef VELOCITYSYSTEM_H_
#define VELOCITYSYSTEM_H_

#include "../ecs/System.h"
#include "../ecs/AllOfAspect.h"
#include "../components/PositionComponent.h"
#include "../components/VelocityComponent.h"

class VelocitySystem: public System {
public:
	VelocitySystem();
	virtual ~VelocitySystem();

	void process_entity(Entity& entity);

};

#endif /* VELOCITYSYSTEM_H_ */
