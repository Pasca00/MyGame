#include <SDL.h>

#pragma once
class Window {
	private:
		int width;
		int height;
		SDL_Window* window;

	public:
		Window();

		SDL_Window* getWindow();

		void resize(int width, int height);

		static const Uint16 BASE_WINDOW_HEIGHT = 720;
		static const Uint16 BASE_WINDOW_WIDTH = 1280;
};

