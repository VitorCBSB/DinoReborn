/*
 * Sprite.h
 *
 *  Created on: 21/12/2013
 *      Author: vitor
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "SDLBase.h"
#include <string>

class Sprite {
private:
	TexturePtr texture;
	SDL_Rect clip;
	double angle;
	bool hidden;

public:
	Sprite(std::string file_name, double angle = 0, bool hidden = false);

	Sprite(const Sprite& other);
	Sprite& operator=(const Sprite& other);
	Sprite(Sprite&& other) :
			texture(std::move(other.texture)), clip(other.clip), angle(
					other.angle), hidden(other.hidden) {
	}

	void clip_texture(SDL_Rect new_clip);
	void render(int x = 0, int y = 0, bool center = true);

	int get_height();
	int get_width();
	int get_height_clipped();
	int get_width_clipped();

	void set_hidden(bool hidden) {
		this->hidden = hidden;
	}

	void set_angle(double angle) {
		this->angle = angle;
	}

	double get_angle() {
		return angle;
	}
};

#endif /* SPRITE_H_ */
