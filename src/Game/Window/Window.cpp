#include "Window.h"

#define GAME_TITLE "MyGame"
#define BASE_WIDTH 1280
#define BASE_HEIGHT 720

Window::Window() {
	height = BASE_HEIGHT;
	width = BASE_HEIGHT;

	window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
								BASE_WIDTH, BASE_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
}

void Window::resize(int width, int height) {
	this->width = width;
	this->height = height;

	// Call SDL function to change window size
}

SDL_Window* Window::getWindow() {
	return window;
}