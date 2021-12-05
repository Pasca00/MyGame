#include "Game.h"

#include "State/MainMenuGameState.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Game* Game::instance = NULL;

class LoadingGameState;

Game::Game() {
	running = true;
	window = new Window();
	setupGL();

	renderer = new Renderer();
	//state_ = new MainMenuGameState(renderer);
	inputCollector = new InputCollector();


	//loadingScreen = new LoadingGameState(renderer);

	transitionRequested = false;
	nextState = NULL;

	startTime = SDL_GetTicks();
	currentTime = startTime;

	stbi_set_flip_vertically_on_load(true);

	std::string filename = "C:/Users/alexp/Desktop/Game/src/Shaders/Test";
	shader = new Shader(filename);

	playBttn = new Texture("C:/Users/alexp/Desktop/Game/resources/Player/player_idle1.png");

	player = new View(playBttn, 0, 0, 3);
}

void Game::setupGL() {
	GLenum error = GL_NO_ERROR;

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glewExperimental = GL_TRUE;
	glContext = SDL_GL_CreateContext(window->getWindow());

	error = glewInit();
	if (error != GLEW_OK) {
		std::cout << "ERROR ON GLEW INIT " << glewGetErrorString(error) << std::endl;
	}
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
	if (input.QUIT || input.KEY_ESCAPE) {
		running = false;
	}
	//state_->handleInput(this, &input);
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
	/*glClearColor(0.2f, 0.2f, 0.9f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);*/

	renderer->clearScreen();
}

void Game::renderQueue() {
	glViewport(0, 0, Window::BASE_WINDOW_WIDTH, Window::BASE_WINDOW_HEIGHT);

	renderer->draw(player, shader);
	//state_->draw();
	//renderer->renderQueue();
}

void Game::update() {
	//state_->update();
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