/*
 * Timer.h
 *
 *  Created on: 04/05/2013
 *      Author: Vitor
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <SDL2/SDL.h>

class Timer {
private:
	bool done;
	bool paused;
	bool started;
	unsigned int goal_time_in_milliseconds;
	unsigned int paused_time_in_milliseconds;
public:
	Timer();
	virtual ~Timer();

	void start(int new_goal_time_in_milliseconds);
	void resume();
	void pause();
	void update();
	unsigned int remaining_time();

	bool is_done() const {
		return done;
	}
};

#endif /* TIMER_H_ */
