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
	Sprite& animation_sheet;
	bool loops;
	double angle;
	int frame_width;
	int frame_height;
	int frame_time_ms;
	int current_frame;
	bool done;
	SDL_Rect current_clip;
	Timer timer;

public:
	Animation(Sprite& animation_sheet, bool loops = true, double angle = 0.0);
	Animation(Sprite& animation_sheet, int frame_width, int frame_height,
			int frame_time, bool loops = true, double angle = 0.0);

	void update();
	void clip_sprite();
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

	double get_angle() const {
		return angle;
	}

	void set_angle(double angle) {
		this->angle = angle;
	}

	bool is_done() const {
		return done;
	}
};

#endif /* ANIMATION_H_ */
