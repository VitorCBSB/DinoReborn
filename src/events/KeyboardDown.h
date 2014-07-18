/*
 * KeyboardDown.h
 *
 *  Created on: 17/07/2014
 *      Author: vitor
 */

#ifndef KEYBOARDDOWN_H_
#define KEYBOARDDOWN_H_

#include "../SDLBase.h"
#include "../ecs/VECS.h"

class KeyboardDown: public Event<KeyboardDown> {
public:
	SDL_Scancode key;

	KeyboardDown(SDL_Scancode key) :
			key(key) {
	}
};

#endif /* KEYBOARDDOWN_H_ */
