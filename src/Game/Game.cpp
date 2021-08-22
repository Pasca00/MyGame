#include "Game.h"
#include "State/MainMenuGameState.h"

Game* Game::instance = NULL;

Game::Game() {
	running = true;
	window = new Window();
	renderer = new Renderer(window);
	state_ = new MainMenuGameState(renderer);
	inputCollector = new InputCollector();

	startTime = SDL_GetTicks();
	currentTime = startTime;
}

bool Game::isRunning() {
	return running;
}

void Game::setRunning(bool state) {
	running = false;
}

Game* Game::getInstance() {
	if (instance == NULL) {
		instance = new Game();
	}

	return instance;
}

Input Game::collectInput() {
	inputCollector->collectInput();
	return inputCollector->getInput();
}

void Game::handleInput(Input input) {
	state_->handleInput(this, &input);
}

Window* Game::getWindow() {
	return window;
}

void Game::renderClearScreen() {
	renderer->clearScreen();
}

void Game::renderQueue() {
	state_->draw();
	renderer->renderQueue();
}

Uint32 Game::getCurrentTime() {
	return SDL_GetTicks() - startTime;
}

Renderer* Game::getRenderer() {
	return renderer;
}