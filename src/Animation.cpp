/*
 * Animation.cpp
 *
 *  Created on: 14/01/2014
 *      Author: vitor
 */

#include "Animation.h"

Animation::Animation(Sprite& animation_sheet, int frame_width, int frame_height,
		int frame_time, bool loops, std::vector<int> num_frames_per_state,
		double angle) :
		animation_sheet(animation_sheet), loops(loops), angle(angle), frame_width(
				frame_width), frame_height(frame_height), frame_time_ms(
				frame_time), current_frame(0), done(false), animation_state(0), num_frames_per_state(
				num_frames_per_state) {
	timer.start(frame_time);
}

Animation::Animation(Sprite& animation_sheet, bool loops,
		std::vector<int> num_frames_per_state, double angle) :
		animation_sheet(animation_sheet), loops(loops), angle(angle), animation_state(
				0), num_frames_per_state(num_frames_per_state) {
	frame_width = animation_sheet.get_width();
	frame_height = animation_sheet.get_height();
	frame_time_ms = 1000;
	current_frame = 0;
	done = false;
}

void Animation::update() {
	timer.update();
	if (timer.is_done()) {
		timer.start(frame_time_ms);

		int next_frame = current_frame + 1;
		next_frame %= num_frames_per_state[animation_state];
		done = !loops && next_frame < current_frame;
		current_frame = next_frame;
	}

	current_clip.x = current_frame * frame_width;
	current_clip.y = animation_state * frame_height;
	current_clip.w = frame_width;
	current_clip.h = frame_height;
}

void Animation::clip_sprite() {
	animation_sheet.clip_texture(current_clip);
}

void Animation::render(int x, int y, bool center) {
	animation_sheet.render(x, y, angle, center);
}
