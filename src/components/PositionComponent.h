/*
 * PositionComponent.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef POSITIONCOMPONENT_H_
#define POSITIONCOMPONENT_H_

#include "../ecs/Component.h"
#include <typeinfo>
#include <string>

class PositionComponent: public Component<PositionComponent> {
public:
	float x, y;

	PositionComponent(float x = 0, float y = 0) :
			Component(), x(x), y(y) {
	}
	virtual ~PositionComponent() {
	}
};

#endif /* POSITIONCOMPONENT_H_ */
