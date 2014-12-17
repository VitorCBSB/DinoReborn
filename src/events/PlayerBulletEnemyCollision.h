/*
 * Collision.h
 *
 *  Created on: 23/07/2014
 *      Author: vitor
 */

#ifndef COLLISION_H_
#define COLLISION_H_

#include "../ecs/VECS.h"

class PlayerBulletEnemyCollision: public Event<PlayerBulletEnemyCollision> {
public:
	EntityPtr enemy, bullet;

	PlayerBulletEnemyCollision(EntityPtr bullet, EntityPtr enemy) :
			enemy(enemy), bullet(bullet) {
	}
};

#endif /* COLLISION_H_ */
