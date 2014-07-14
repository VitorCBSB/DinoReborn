/*
 * SDLBase.h
 *
 *  Created on: 14/07/2014
 *      Author: vitor
 */

#ifndef SDLBASE_H_
#define SDLBASE_H_

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>
#include <stdlib.h>
#include <stdio.h>

template<typename T, void (*Del)(T*)>
struct Deleter {
	void operator()(T* ptr) const {
		Del(ptr);
	}
};

typedef Deleter<SDL_Window, SDL_DestroyWindow> WindowDeleter;
typedef std::unique_ptr<SDL_Window, WindowDeleter> WindowPtr;

typedef Deleter<SDL_Renderer, SDL_DestroyRenderer> RendererDeleter;
typedef std::unique_ptr<SDL_Renderer, RendererDeleter> RendererPtr;

typedef Deleter<SDL_Texture, SDL_DestroyTexture> TextureDeleter;
typedef std::unique_ptr<SDL_Texture, TextureDeleter> TexturePtr;

class SDLBase {
private:
	static SDL_Window* window;
	static SDL_Renderer* screen_renderer;

public:
	static void initialize_SDL();
	static void finalize_SDL();

	static TexturePtr load_image(std::string file_name);
	static void render_texture(SDL_Texture* texture, SDL_Rect* clip,
			SDL_Rect* dst);
	static void update_screen();
	static void clear_screen();
};

#endif /* SDLBASE_H_ */
