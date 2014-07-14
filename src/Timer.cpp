/*
 * Timer.cpp
 *
 *  Created on: 04/05/2013
 *      Author: Vitor
 */

#include "Timer.h"

Timer::Timer() {
	done = false;
	paused = false;
	started = false;
	goal_time_in_milliseconds = 0;
	paused_time_in_milliseconds = 0;
}

Timer::~Timer() {
}

void Timer::update() {
	if (!done && !paused && started
			&& SDL_GetTicks() >= goal_time_in_milliseconds) {
		done = true;
		started = false;
	}
}

void Timer::start(int new_goal_time_in_milliseconds) {
	this->goal_time_in_milliseconds = SDL_GetTicks() + new_goal_time_in_milliseconds;
	done = false;
	paused = false;
	started = true;
}

void Timer::pause() {
	if (!paused && started) {
		paused = true;
		paused_time_in_milliseconds = SDL_GetTicks();
	}
}

void Timer::resume() {
	if (paused) {
		paused = false;
		goal_time_in_milliseconds = goal_time_in_milliseconds
				+ (SDL_GetTicks() - paused_time_in_milliseconds);
	}
}

unsigned int Timer::remaining_time() {
	if (done || !started) {
		return 0;
	}
	if (paused) {
		return goal_time_in_milliseconds - paused_time_in_milliseconds;
	}
	return goal_time_in_milliseconds - SDL_GetTicks();
}
