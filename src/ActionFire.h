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
#include "components/marker/PlayerBulletMarker.h"
#include "parser/BulletDefinition.h"
#include "Direction.h"

class ActionFire: public Action {
private:
	Direction direction;
	Expression speed;
	BulletDefinition bullet_definition;

	float get_angle_based_on_type(World& world, Entity& bullet);

public:
	ActionFire(Direction direction, Expression speed,
			BulletDefinition bullet_definition) :
			Action(Action::FIRE), direction(direction), speed(speed), bullet_definition(
					bullet_definition) {
	}

	bool update(World& world, Entity& bullet, double dt);
	void set_repeat_to(int new_value) {
		direction.set_repeat_to(new_value);
		speed.set_repeat_to(new_value);
	}
	ActionPtr clone() {
		return ActionPtr(new ActionFire(*this));
	}
};

#endif /* ACTIONFIRE_H_ */
