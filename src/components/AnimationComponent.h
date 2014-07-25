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

class AnimationComponent: public Component<AnimationComponent> {
public:
	Animation animation;
	int priority;

	AnimationComponent() :
			animation(
					Animation(Sprite("img/not_defined.png"), 48, 48, 1000,
							true)), priority(100) {
	}
	AnimationComponent(Sprite sprite, int priority) :
			animation(
					Animation(std::move(sprite), sprite.get_width(),
							sprite.get_height(), 10000, true)), priority(
					priority) {
	}
	AnimationComponent(Animation animation, int priority) :
			animation(std::move(animation)), priority(priority) {
	}
};

#endif /* ANIMATIONCOMPONENT_H_ */
