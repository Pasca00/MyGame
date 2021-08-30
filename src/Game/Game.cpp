#include "Game.h"

#include "State/MainMenuGameState.h"

Game* Game::instance = NULL;

class LoadingGameState;

Game::Game() {
	running = true;
	window = new Window();
	renderer = new Renderer(window);
	state_ = new MainMenuGameState(renderer);
	inputCollector = new InputCollector();

	loadingScreen = new LoadingGameState(renderer);

	transitionRequested = false;
	nextState = NULL;

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

void Game::requestTransition(GameState* nextState) {
	transitionRequested = true;
	this->nextState = nextState;
}

void Game::changeState() {
	if (transitionRequested == false) {
		return;
	}

	GameState* currentState = state_;
	state_ = nextState;
	state_->enter();
	transitionRequested = false;
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

void Game::update() {
	state_->update();
}

Uint32 Game::getCurrentTime() {
	return SDL_GetTicks() - startTime;
}

Renderer* Game::getRenderer() {
	return renderer;
}

GameState* Game::getState() {
	return state_;
}

void Game::setState(GameState* state_) {
	this->state_ = state_;
}

LoadingGameState* Game::getLoadScreen() {
	return loadingScreen;
}

void Game::loadLevel() {
	requestTransition(loadingScreen);
}