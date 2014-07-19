/*
 * SpriteComponent.h
 *
 *  Created on: 14/07/2014
 *      Author: vitor
 */

#ifndef SPRITECOMPONENT_H_
#define SPRITECOMPONENT_H_

#include "../Sprite.h"
#include "../ecs/VECS.h"

class SpriteComponent: public Component<SpriteComponent> {
public:
	Sprite sprite;
	int priority;

	SpriteComponent(std::string sprite_file_name = "../img/not_defined.png",
			int priority = 100) :
			sprite(Sprite(sprite_file_name)), priority(priority) {
	}
};

#endif /* SPRITECOMPONENT_H_ */
