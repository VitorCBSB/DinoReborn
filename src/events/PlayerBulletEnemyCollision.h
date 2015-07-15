/*
 * Collision.h
 *
 *  Created on: 23/07/2014
 *      Author: vitor
 */

#ifndef COLLISION_H_
#define COLLISION_H_

#include "../ecs/VECS.h"
#include <functional>

class PlayerBulletEnemyCollision: public Event<PlayerBulletEnemyCollision> {
public:
	std::reference_wrapper<Entity> enemy, bullet;

	PlayerBulletEnemyCollision(Entity& bullet, Entity& enemy) :
			enemy(enemy), bullet(bullet) {
	}
};

#endif /* COLLISION_H_ */
