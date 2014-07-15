/*
 * InputSystem.h
 *
 *  Created on: 15/07/2014
 *      Author: vitor
 */

#ifndef INPUTSYSTEM_H_
#define INPUTSYSTEM_H_

#include "../ecs/VECS.h"
#include <map>
#include <stdint.h>

class InputSystem : public System<InputSystem> {
public:
	void process_entities(std::map<uint64_t, EntityPtr>& entities, double dt);
	void process_entity(Entity& entity, double dt);
};

#endif /* INPUTSYSTEM_H_ */
