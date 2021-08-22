#pragma once
#include "../Input/InputCollector.h"

class Game;
class State {
	private:
		Uint32 startTime;
		Uint32 currentTime;

	public:
		State() {
			startTime = SDL_GetTicks();
			currentTime = startTime;
		}

		virtual void handleInput(Game *game, Input *input) = 0;
};

