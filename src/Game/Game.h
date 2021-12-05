#pragma once

#include <string>
#include <iostream>

#define GLEW_STATIC
#include <gl/glew.h>
#include <SDL_opengl.h>
#include <gl/GLU.h>
#include <gl/GL.h>

#include <SDL.h>

#include <thread>

#include "State/GameState.h"
#include "State/LoadingGameState.h"

#include "Window/Window.h"
#include "Render/Renderer.h"

#include "Visuals/Core/Texture.h"
#include "Visuals/Core/Quad.h"
#include "Visuals/Core/Shader.h"

class Game {
	private: 
		static Game* instance;
		bool running;
		Window* window;
		Renderer* renderer;
		
		GameState* state_;
		LoadingGameState* loadingScreen;

		InputCollector* inputCollector;

		bool transitionRequested;
		GameState* nextState;

		Uint32 startTime;
		Uint32 currentTime;

		SDL_GLContext glContext;
		
		Texture* playBttn;
		Quad* quad;
		Shader* shader;
		View* player;

		Game();
		void setupGL();

	public:
		static Game* getInstance();
		bool isRunning();
		void setRunning(bool state);

		Input collectInput();
		void handleInput(Input input);

		Window* getWindow();
		void renderClearScreen();
		void renderQueue();
		void update();

		Uint32 getCurrentTime();
		Renderer* getRenderer();

		GameState* getState();
		void setState(GameState* nextState_);

		LoadingGameState* getLoadScreen();
		void loadLevel();
		void requestTransition(GameState* nextState);
		void changeState();
};

