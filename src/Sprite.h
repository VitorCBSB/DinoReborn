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
	bool hidden;

public:
	Sprite(std::string file_name, bool hidden = false);

	void clip_texture(SDL_Rect new_clip);
	void render(int x = 0, int y = 0, bool center = true);

	int get_height();
	int get_width();
	int get_height_clipped();
	int get_width_clipped();

	void set_hidden(bool hidden) {
		this->hidden = hidden;
	}
};

#endif /* SPRITE_H_ */