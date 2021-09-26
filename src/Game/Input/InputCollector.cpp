#include "InputCollector.h"

InputCollector::InputCollector() {
	SDL_memset(&input, 0, sizeof(input));
}

void InputCollector::flushInputs() {
	SDL_memset(&input, 0, sizeof(input));
}

Input InputCollector::getInput() {
	return input;
}

void InputCollector::flushInput(Input* input) {
	SDL_memset(input, 0, sizeof(Input));
}

void InputCollector::collectInput() {
	SDL_PumpEvents();
	SDL_GetMouseState(&(input.MOUSE_X), &(input.MOUSE_Y));

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				input.QUIT = true;
				break;
			
			case SDL_MOUSEBUTTONDOWN:
				switch (event.button.button) {
					case SDL_BUTTON_LEFT:
						input.LEFT_MOUSE_CLICK = true;
						break;

					case SDL_BUTTON_RIGHT:
						input.RIGHT_MOUSE_CLICK = true;
						break;
				}
				break;

			case SDL_MOUSEBUTTONUP:
				switch (event.button.button) {
					case SDL_BUTTON_LEFT:
						input.LEFT_MOUSE_CLICK = false;
						break;

					case SDL_BUTTON_RIGHT:
						input.RIGHT_MOUSE_CLICK = false;
						break;
				}

				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_w:
						input.KEY_W = true;
						break;

					case SDLK_a:
						input.KEY_A = true;
						break;

					case SDLK_s:
						input.KEY_S = true;
						break;

					case SDLK_d:
						input.KEY_D = true;
						break;

					case SDLK_SPACE:
						input.KEY_SPACE = true;
						break;

					case SDLK_ESCAPE:
						input.KEY_ESCAPE = true;
						input.QUIT = true;
						break;
				}

				break;

			case SDL_KEYUP:
				switch (event.key.keysym.sym) {
					case SDLK_w:
						input.KEY_W = false;
						break;

					case SDLK_a:
						input.KEY_A = false;
						break;

					case SDLK_s:
						input.KEY_S = false;
						break;

					case SDLK_d:
						input.KEY_D = false;
						break;

					case SDLK_SPACE:
						input.KEY_SPACE = false;
						break;

					case SDLK_ESCAPE:
						input.KEY_ESCAPE = false;
						break;
				}

				break;
		}
	}
}