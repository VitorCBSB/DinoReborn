/*
 * Animation.h
 *
 *  Created on: 14/01/2014
 *      Author: vitor
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "Sprite.h"
#include "Timer.h"

class Animation {
private:
	Sprite animation_sheet;
	int frame_width;
	int frame_height;
	int frame_time_ms;
	int current_frame;
	bool loops;
	bool done;
	Timer timer;

public:
	Animation(Sprite animation_sheet, int frame_width, int frame_height,
			int frame_time, bool loops = false);

	Animation(const Animation& other);
	Animation(Animation&& other) :
			animation_sheet(std::move(other.animation_sheet)), frame_width(
					other.frame_width), frame_height(other.frame_height), frame_time_ms(
					other.frame_time_ms), current_frame(other.current_frame), loops(
					other.loops), done(other.done), timer(other.timer) {
	}

	void update();
	void render(int x, int y, bool center = true);

	int get_frame_height() const {
		return frame_height;
	}

	void set_frame_height(int frame_height) {
		this->frame_height = frame_height;
	}

	int get_frame_time() const {
		return frame_time_ms;
	}

	void set_frame_time(int frame_time) {
		this->frame_time_ms = frame_time;
	}

	int get_frame_width() const {
		return frame_width;
	}

	void set_frame_width(int frame_width) {
		this->frame_width = frame_width;
	}

	bool is_done() const {
		return done;
	}
};

#endif /* ANIMATION_H_ */
