/*
 * InputManager.h
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include "SDLBase.h"

#define N_MOUSE_BUTTONS 7

class InputManager {
private:
	static InputManager* instance;

	Uint32 mouseState;
	Uint8 keyStates[SDL_NUM_SCANCODES];
	Uint8 oldKeyStates[SDL_NUM_SCANCODES];
	bool quitGame;
	int mouseX;
	int mouseY;

	int keyDownUp[SDL_NUM_SCANCODES];
	bool mouseDown[N_MOUSE_BUTTONS];
	bool mouseUp[N_MOUSE_BUTTONS];

	void initMouse();

	InputManager();

public:
	static InputManager* get() {
		if (!instance) {
			instance = new InputManager();
		}
		return instance;
	}

	void update();
	bool isKeyDown(int key);
	bool isKeyUp(int key);
	bool isKeyHeld(int key);
	bool isMouseDown(int button);
	bool isMouseUp(int button);
	bool isMouseHeld(int button);
	int mousePosX();
	int mousePosY();
	bool isMouseInside(SDL_Rect rect);
	bool QuitGame();
};

#endif /* INPUTMANAGER_H_ */
