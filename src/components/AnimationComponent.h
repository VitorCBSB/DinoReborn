/*
 * AnimationComponent.h
 *
 *  Created on: 25/07/2014
 *      Author: vitor
 */

#ifndef ANIMATIONCOMPONENT_H_
#define ANIMATIONCOMPONENT_H_

#include "../ecs/VECS.h"
#include "../Animation.h"
#include "../Sprite.h"
#include "../GameAnimations.h"

class AnimationComponent: public Component<AnimationComponent> {
public:
	Animation animation;
	int priority;

	AnimationComponent() :
			animation(
					Animation(GameAnimations::sprites["img/not_defined.png"],
							48, 48, 1000, 0, true)), priority(100) {
	}
	AnimationComponent(Sprite& sprite, double angle, int priority) :
			animation(
					Animation(sprite, sprite.get_width(), sprite.get_height(),
							10000, angle, true)), priority(priority) {
	}
	AnimationComponent(Animation animation, int priority) :
			animation(animation), priority(priority) {
	}
};

#endif /* ANIMATIONCOMPONENT_H_ */
