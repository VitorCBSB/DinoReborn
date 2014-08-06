/*
 * ActionFire.h
 *
 *  Created on: 05/08/2014
 *      Author: vitor
 */

#ifndef ACTIONFIRE_H_
#define ACTIONFIRE_H_

#include "ecs/VECS.h"
#include "Action.h"
#include "parser/Expression.h"
#include "EntityFactory.h"
#include "components/PositionComponent.h"
#include "components/VelocityComponent.h"
#include "parser/BulletDefinition.h"

class ActionFire: public Action {
private:
	Expression direction;
	Expression speed;
	BulletDefinition bullet_definition;

	float get_angle_based_on_type(World& world, Entity& bullet);

public:
	enum DirectionType {
		ABSOLUTE, RELATIVE, AIM
	};
	ActionFire(Expression direction, DirectionType direction_type,
			Expression speed, BulletDefinition bullet_definition) :
			direction(direction), speed(speed), direction_type(direction_type), bullet_definition(bullet_definition) {
	}

	bool update(World& world, Entity& bullet, double dt);
	void increment_repeat() {
		direction.increment_repeat();
		speed.increment_repeat();
	}

private:
	DirectionType direction_type;
};

#endif /* ACTIONFIRE_H_ */
