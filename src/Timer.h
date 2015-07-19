/*
 * Timer.h
 *
 *  Created on: 04/05/2013
 *      Author: Vitor
 */

#ifndef TIMER_H_
#define TIMER_H_

class Timer {
private:
	bool done;
	bool paused;
	bool started;
	unsigned int goal_time_in_frames;
	unsigned int paused_time_in_frames;
	unsigned int current;
public:
	Timer() :
			done(false), paused(false), started(false), goal_time_in_frames(
					0), paused_time_in_frames(0), current(0) {
	}

	void start(int new_goal_time_in_frames);
	void resume();
	void pause();
	void update();
	unsigned int remaining_time();

	bool is_done() const {
		return done;
	}
};

#endif /* TIMER_H_ */
