/*
 * Direction.h
 *
 *  Created on: 08/08/2014
 *      Author: vitor
 */

#ifndef DIRECTION_H_
#define DIRECTION_H_

#include "parser/Expression.h"
#include "ecs/VECS.h"
#include "Vector2.h"
#include "components/VelocityComponent.h"
#include "components/PositionComponent.h"
#include <math.h>

class Direction {
private:
	Expression direction;
public:
	enum DirectionType {
		ABSOLUTE, RELATIVE, AIM
	};
	Direction(Expression direction, DirectionType type) :
			direction(direction), type(type) {
	}
	float get_angle(World& world, Entity& bullet);
	void increment_repeat() {
		direction.increment_repeat();
	}

private:
	DirectionType type;
};

#endif /* DIRECTION_H_ */
