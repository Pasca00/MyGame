#include "Game.h"

#include "State/MainMenuGameState.h"
#include "glm/gtc/matrix_transform.hpp"

Game* Game::instance = NULL;

class LoadingGameState;

Game::Game() {
	running = true;
	window = new Window();
	setupGL();
	//renderer = new Renderer(window);
	//state_ = new MainMenuGameState(renderer);
	inputCollector = new InputCollector();

	//loadingScreen = new LoadingGameState(renderer);

	transitionRequested = false;
	nextState = NULL;

	startTime = SDL_GetTicks();
	currentTime = startTime;

	playBttn = new Texture("C:/Users/alexp/Desktop/Game/resources/play_button.png");

	std::vector<Vertex> vertices = {
		Vertex(glm::vec3(0.f, 0.f, 0.f), glm::vec3(1), glm::vec2(0.f, 0.f)),
		Vertex(glm::vec3(1.f, 0.f, 0.f), glm::vec3(1), glm::vec2(1.f, 0.f)),
		Vertex(glm::vec3(1.f, 1.f, 0.f), glm::vec3(1), glm::vec2(1.f, 1.f)),
	};

	std::vector<unsigned int> indices = {
		0, 1, 2
	};

	quad = new Quad(vertices, indices);
	std::string filename = "C:/Users/alexp/Desktop/Game/src/Shaders/Test";
	shader = new Shader(filename);
}

void Game::setupGL() {
	GLenum error = GL_NO_ERROR;

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	glewExperimental = GL_TRUE;

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

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
	glClearColor(0.2f, 0.2f, 0.9f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(window->getWindow());
}

void Game::renderQueue() {
	//state_->draw();
	//renderer->renderQueue();
	glm::mat4 modelMatrix(1);
	
	shader->use();
	shader->setModelMatrix(modelMatrix);
	shader->setProjectionMatrix(glm::ortho(0.0f, 4.0f, 0.0f, 3.0f, 0.1f, 100.0f));

	//glActiveTexture(playBttn->getTextureID());

	glBindVertexArray(quad->getVAO());
	glDrawElementsBaseVertex(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (void*)(sizeof(unsigned int) * 3), 0);
	GLenum error = glGetError();
	if (error == GL_INVALID_ENUM) {
		printf("error\n");
	}
	glBindVertexArray(0);
}

void Game::update() {
	glViewport(0, 0, Window::BASE_WINDOW_WIDTH, Window::BASE_WINDOW_HEIGHT);
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