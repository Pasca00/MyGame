#include "LoadingGameState.h"
#include "../Game.h"

LoadingGameState::LoadingGameState() {
	std::vector<Texture*> textures(4, NULL);
	textures[0] = new Texture("C:/Users/alexp/Desktop/Game/resources/mini/loading1.png");
	textures[1] = new Texture("C:/Users/alexp/Desktop/Game/resources/mini/loading2.png");
	textures[2] = new Texture("C:/Users/alexp/Desktop/Game/resources/mini/loading3.png");
	textures[3] = new Texture("C:/Users/alexp/Desktop/Game/resources/mini/loading4.png");
	
	float w, h;
	w = textures[0]->getWidth();
	h = textures[0]->getHeight();

	float x = (Window::BASE_WINDOW_WIDTH - w * 3) / 2.f;
	float y = (Window::BASE_WINDOW_HEIGHT- h * 3) / 2.f;

	loadingAnimation = new Animation(textures, 180, x, y, 3);
}

void LoadingGameState::enter() {
	loaderIsReady = false;
	
	/*loaderThread = std::thread([this] {
		s_ = new PlayingGameState();
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		loaderIsReady = true;
	});*/
}

void LoadingGameState::handleInput(Game* game, Input* input) {
	if (input->KEY_ESCAPE || input->QUIT) {
		game->setRunning(false);
	}
}

void LoadingGameState::update() {
	loadingAnimation->update();

	Game::getInstance()->requestTransition(new PlayingGameState());
	/*if (loaderIsReady) {
		loaderThread.join();
		Game::getInstance()->requestTransition(s_);
	}*/
}

void LoadingGameState::draw() {
	Game::getInstance()->getRenderer()->draw(loadingAnimation->getCurrentFrame(), Game::getInstance()->baseTextureShader);
}
