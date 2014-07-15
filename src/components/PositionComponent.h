/*
 * PositionComponent.h
 *
 *  Created on: 11/07/2014
 *      Author: vitor
 */

#ifndef POSITIONCOMPONENT_H_
#define POSITIONCOMPONENT_H_

#include "../ecs/VECS.h"
#include "../Vector2.h"

class PositionComponent: public Component<PositionComponent> {
public:
	Vector2 position;

	PositionComponent(float x = 0, float y = 0) :
			Component(), position(Vector2(x, y)) {
	}
};

#endif /* POSITIONCOMPONENT_H_ */
