#include "LoadingGameState.h"
#include "../Game.h"

LoadingGameState::LoadingGameState(Renderer* renderer) {
	std::vector<Texture*> textures(4, NULL);
	textures[0] = new Texture("C:/Users/alexp/Desktop/Game/resources/mini/loading1.png");
	textures[1] = new Texture("C:/Users/alexp/Desktop/Game/resources/mini/loading2.png");
	textures[2] = new Texture("C:/Users/alexp/Desktop/Game/resources/mini/loading3.png");
	textures[3] = new Texture("C:/Users/alexp/Desktop/Game/resources/mini/loading4.png");

	SDL_Rect dstrect;
	dstrect.w = dstrect.h = 64;
	
	float w, h;
	w = textures[0]->getWidth();
	h = textures[0]->getHeight();

	float x = (Window::BASE_WINDOW_WIDTH - dstrect.w) / 2;
	float y = (Window::BASE_WINDOW_HEIGHT- dstrect.h) / 2;

	loadingAnimation = new Animation(textures, 200, x, y, 1);
}

void LoadingGameState::enter() {
	loaderIsReady = false;

	/*oaderThread = std::thread([this] {
		s_ = new PlayingGameState();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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
	
	s_ = new PlayingGameState();
	Game::getInstance()->requestTransition(s_);

	//if (loaderIsReady) {
	//	loaderThread.join();
	//	Game::getInstance()->requestTransition(s_);
	//}
}

void LoadingGameState::draw() {
	Game::getInstance()->getRenderer()->addToQueue(loadingAnimation->getCurrentFrame());
}
