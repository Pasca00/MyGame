#pragma once
#include <string>
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include "State/GameState.h"
#include "Window/Window.h"
#include "Render/Renderer.h"

class Game {
	private: 
		static Game* instance;
		bool running;
		Window* window;
		Renderer* renderer;
		GameState* state_;
		InputCollector* inputCollector;

		Uint32 startTime;
		Uint32 currentTime;
		// Should probably keep track of time
		// in each separate game state

		Game();

	public:
		static Game* getInstance();
		bool isRunning();
		void setRunning(bool state);

		Input collectInput();
		void handleInput(Input input);

		Window* getWindow();
		void renderClearScreen();
		void renderQueue();

		Uint32 getCurrentTime();
		Renderer* getRenderer();
};

