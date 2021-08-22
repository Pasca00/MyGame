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
};

