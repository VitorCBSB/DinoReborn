/*
 * KeyboardUp.h
 *
 *  Created on: 17/07/2014
 *      Author: vitor
 */

#ifndef KEYBOARDUP_H_
#define KEYBOARDUP_H_

#include "../SDLBase.h"
#include "../ecs/VECS.h"

class KeyboardUp : public Event<KeyboardUp> {
public:
	SDL_Scancode key;

	KeyboardUp(SDL_Scancode key) : key(key) {}
};

#endif /* KEYBOARDUP_H_ */
