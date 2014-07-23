/*
 * Collision.h
 *
 *  Created on: 23/07/2014
 *      Author: vitor
 */

#ifndef COLLISION_H_
#define COLLISION_H_

#include "../ecs/VECS.h"

class Collision: public Event<Collision> {
public:
	EntityPtr entity, bullet;

	Collision(EntityPtr entity, EntityPtr bullet) :
			entity(entity), bullet(bullet) {
	}
};

#endif /* COLLISION_H_ */
