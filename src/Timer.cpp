/*
 * Timer.cpp
 *
 *  Created on: 04/05/2013
 *      Author: Vitor
 */

#include "Timer.h"

void Timer::update() {
	if (!done && !paused && started
			&& current++ >= goal_time_in_frames) {
		done = true;
		started = false;
	}
}

void Timer::start(int new_goal_time_in_frames) {
	current = 0;
	this->goal_time_in_frames = new_goal_time_in_frames;
	done = false;
	paused = false;
	started = true;
}

void Timer::pause() {
	if (!paused && started) {
		paused = true;
	}
}

void Timer::resume() {
	if (paused) {
		paused = false;
	}
}

unsigned int Timer::remaining_time() {
	if (done || !started) {
		return 0;
	}
	return goal_time_in_frames - current;
}
