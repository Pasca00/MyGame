#include "Game.h"

#include "State/MainMenuGameState.h"

Game* Game::instance = NULL;

class LoadingGameState;

Game::Game() {
	running = true;
	window = new Window();
	//setupGL();
	renderer = new Renderer(window);
	state_ = new MainMenuGameState(renderer);
	inputCollector = new InputCollector();

	loadingScreen = new LoadingGameState(renderer);

	transitionRequested = false;
	nextState = NULL;

	startTime = SDL_GetTicks();
	currentTime = startTime;
}

void Game::setupGL() {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);

	SDL_GLContext context = SDL_GL_CreateContext(window->getWindow());

	if (context == NULL) {
		printf("error initializing GL context\n");
	}

	glClearColor(1.f, 0.f, 1.f, 0.f);
	glViewport(0, 0, Window::BASE_WINDOW_WIDTH, Window::BASE_WINDOW_HEIGHT);
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
	//inputCollector->flushInputs();
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