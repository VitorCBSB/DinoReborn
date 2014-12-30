/*
 * SDLBase.cpp
 *
 *  Created on: 14/07/2014
 *      Author: vitor
 */

#include "SDLBase.h"

SDL_Window* SDLBase::window;
SDL_Renderer* SDLBase::screen_renderer;

void SDLBase::initialize_SDL(int window_width, int window_height) {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Dino em' Up", 500, 500, window_width,
	window_height, SDL_WINDOW_SHOWN);
	screen_renderer = SDL_CreateRenderer(window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void SDLBase::finalize_SDL() {
	SDL_DestroyRenderer(screen_renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

TexturePtr SDLBase::load_image(std::string file_name) {
	TexturePtr texture(IMG_LoadTexture(screen_renderer, file_name.c_str()));
	if (texture == nullptr) {
		fprintf(stderr, "Could not load image %s\n", file_name.c_str());
		exit(1);
	}
	return texture;
}

void SDLBase::render_texture(SDL_Texture* texture, SDL_Rect* clip,
		SDL_Rect* dst, double angle) {
	if (SDL_RenderCopyEx(screen_renderer, texture, clip, dst, angle, nullptr,
			SDL_FLIP_NONE) == -1) {
		fprintf(stderr, "Could not render image with %dx%d dimensions.\n",
				clip->w, clip->h);
		exit(1);
	}
}

void SDLBase::update_screen() {
	SDL_RenderPresent(screen_renderer);
}

void SDLBase::clear_screen() {
	SDL_RenderClear(screen_renderer);
}
