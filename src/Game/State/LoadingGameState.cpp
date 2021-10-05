#include "LoadingGameState.h"
#include "../Game.h"

LoadingGameState::LoadingGameState(Renderer* renderer) {
	std::vector<SDL_Texture*> textures(4, NULL);
	textures[0] = IMG_LoadTexture(renderer->getSDLRenderer(), "C:/Users/alexp/Desktop/Game/resources/mini/loading1.png");
	textures[1] = IMG_LoadTexture(renderer->getSDLRenderer(), "C:/Users/alexp/Desktop/Game/resources/mini/loading2.png");
	textures[2] = IMG_LoadTexture(renderer->getSDLRenderer(), "C:/Users/alexp/Desktop/Game/resources/mini/loading3.png");
	textures[3] = IMG_LoadTexture(renderer->getSDLRenderer(), "C:/Users/alexp/Desktop/Game/resources/mini/loading4.png");

	SDL_Rect dstrect;
	dstrect.w = dstrect.h = 64;
	dstrect.x = (Window::BASE_WINDOW_WIDTH - dstrect.w) / 2;
	dstrect.y = (Window::BASE_WINDOW_HEIGHT- dstrect.h) / 2;

	loadingAnimation = new Animation(textures, dstrect, 200);
}

void LoadingGameState::enter() {
	loaderIsReady.store(false);

	loaderThread = std::thread([this] {
		s_.store(new PlayingGameState());
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		loaderIsReady.store(true);
	});
}

void LoadingGameState::handleInput(Game* game, Input* input) {
	if (input->KEY_ESCAPE || input->QUIT) {
		game->setRunning(false);
	}
}

void LoadingGameState::update() {
	if (loaderIsReady.load()) {
		loaderThread.detach();
		Game::getInstance()->requestTransition(s_.load());
	}
	
	loadingAnimation->update();
}

void LoadingGameState::draw() {
	Game::getInstance()->getRenderer()->addToQueue(loadingAnimation->getCurrentFrame());
}
