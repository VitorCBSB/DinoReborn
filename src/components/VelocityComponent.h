/*
 * VelocityComponent.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef VELOCITYCOMPONENT_H_
#define VELOCITYCOMPONENT_H_

#include "../ecs/Component.h"
#include <typeinfo>

class VelocityComponent: public Component<VelocityComponent> {
public:
	float x, y;

	VelocityComponent(float x = 0, float y = 0) :
			Component(), x(x), y(y) {
	}
	virtual ~VelocityComponent() {
	}
};

#endif /* VELOCITYCOMPONENT_H_ */
