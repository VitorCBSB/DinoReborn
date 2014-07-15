/*
 * InputManager.cpp
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#include "InputManager.h"

InputManager* InputManager::instance = NULL;

InputManager::InputManager() :
		mouseState(0), quitGame(false), mouseX(0), mouseY(0) {
	initMouse();
}

void InputManager::initMouse() {
	for (int i = 0; i < N_MOUSE_BUTTONS; i++) {
		mouseDown[i] = mouseUp[i] = false;
	}
}

void InputManager::update() {
	SDL_Event event;

	if (keyStates) {
		memcpy(oldKeyStates, keyStates, SDL_NUM_SCANCODES * sizeof(Uint8));
	}
	Uint8* tempKeyStates = (Uint8*) SDL_GetKeyboardState(NULL);
	memcpy(keyStates, tempKeyStates, SDL_NUM_SCANCODES * sizeof(Uint8));
	mouseState = SDL_GetMouseState(&mouseX, &mouseY);

	initMouse();

	for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
		keyDownUp[i] = (int) keyStates[i] - (int) oldKeyStates[i];
	}

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_MOUSEBUTTONDOWN:
			mouseDown[event.button.button] = true;
			break;
		case SDL_MOUSEBUTTONUP:
			mouseUp[event.button.button] = true;
			break;
		case SDL_QUIT:
			quitGame = true;
			break;
		default:
			break;
		}
	}
}

bool InputManager::isKeyDown(int key) {
	return keyDownUp[key] > 0;
}

bool InputManager::isKeyUp(int key) {
	return keyDownUp[key] < 0;
}

bool InputManager::isKeyHeld(int key) {
	return keyStates[key];
}

bool InputManager::isMouseDown(int button) {
	return mouseDown[button];
}

bool InputManager::isMouseUp(int button) {
	return mouseUp[button];
}

bool InputManager::isMouseHeld(int button) {
	return mouseState & button;
}

int InputManager::mousePosX() {
	return mouseX;
}

int InputManager::mousePosY() {
	return mouseY;
}

bool InputManager::isMouseInside(SDL_Rect rect) {
	return mouseX >= rect.x && (mouseX <= rect.x + rect.w) && mouseY >= rect.y
			&& (mouseY <= rect.y + rect.h);
}

bool InputManager::QuitGame() {
	return quitGame;
}
