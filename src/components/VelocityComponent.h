/*
 * VelocityComponent.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef VELOCITYCOMPONENT_H_
#define VELOCITYCOMPONENT_H_

#include "../ecs/VECS.h"
#include "../Vector2.h"

class VelocityComponent: public Component<VelocityComponent> {
public:
	Vector2 velocity;

	VelocityComponent(float x = 0, float y = 0) :
			Component(), velocity(Vector2(x, y)) {
	}
	virtual ~VelocityComponent() {
	}
};

#endif /* VELOCITYCOMPONENT_H_ */
