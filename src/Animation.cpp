/*
 * Animation.cpp
 *
 *  Created on: 14/01/2014
 *      Author: vitor
 */

#include "Animation.h"

Animation::Animation(Sprite animation_sheet, int frame_width, int frame_height,
		int frame_time, bool loops) :
		animation_sheet(std::move(animation_sheet)), frame_width(frame_width), frame_height(
				frame_height), frame_time_ms(frame_time), current_frame(0), loops(
				loops), done(false) {
	timer.start(frame_time);
}

void Animation::update() {
	timer.update();
	if (timer.is_done()) {
		timer.start(frame_time_ms);

		int next_frame = current_frame + 1;
		next_frame %= (animation_sheet.get_width() / frame_width);
		done = !loops && next_frame < current_frame;
		current_frame = next_frame;
	}

	SDL_Rect clip;
	clip.x = current_frame * frame_width;
	clip.y = 0;
	clip.w = frame_width;
	clip.h = frame_height;

	animation_sheet.clip_texture(clip);
}

void Animation::render(int x, int y, bool center) {
	animation_sheet.render(x, y, center);
}
