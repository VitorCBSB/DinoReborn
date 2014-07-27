/*
 * Sprite.cpp
 *
 *  Created on: 21/12/2013
 *      Author: vitor
 */

#include "Sprite.h"

Sprite::Sprite(std::string file_name, bool hidden) :
		texture(SDLBase::load_image(file_name)) {
	this->clip.x = this->clip.y = 0;
	SDL_QueryTexture(texture.get(), nullptr, nullptr, &clip.w, &clip.h);
	this->hidden = hidden;
}

void Sprite::clip_texture(SDL_Rect newClip) {
	this->clip = newClip;
}

// Essa função tenta evitar o 'stretching'
// Que o SDL_RenderCopy faz. :/
void Sprite::render(int x, int y, double angle, bool center) {
	if (hidden) {
		return;
	}

	SDL_Rect dst;
	int textureW, textureH;

	SDL_QueryTexture(texture.get(), nullptr, nullptr, &textureW, &textureH);

	dst.x = center ? x - (std::min(clip.w, textureW) / 2) : x;
	dst.y = center ? y - (std::min(clip.h, textureH) / 2) : y;
	dst.w = std::min(clip.w, textureW);
	dst.h = std::min(clip.h, textureH);

	SDLBase::render_texture(texture.get(), &clip, &dst, angle);
}

int Sprite::get_height() {
	int height;
	SDL_QueryTexture(texture.get(), nullptr, nullptr, nullptr, &height);
	return height;
}

int Sprite::get_width() {
	int width;
	SDL_QueryTexture(texture.get(), nullptr, nullptr, &width, nullptr);
	return width;
}

int Sprite::get_height_clipped() {
	return clip.h;
}

int Sprite::get_width_clipped() {
	return clip.w;
}
