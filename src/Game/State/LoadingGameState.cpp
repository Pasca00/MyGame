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
	dstrect.x = dstrect.y = 0;

	loadingAnimation = new Animation(textures, dstrect, 250);
}

void LoadingGameState::enter() {
	loaderFuture = loaderPromise.get_future();

	loaderThread = std::thread([this] {
		PlayingGameState* s_ = new PlayingGameState();
		loaderPromise.set_value(s_);
	});
}

bool LoadingGameState::loaderIsReady() {
	return loaderFuture.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
}

void LoadingGameState::update() {
	if (loaderIsReady()) {
		loaderThread.join();
		PlayingGameState* s_ = loaderFuture.get();
		Game::getInstance()->requestTransition(s_);
	}
	
	loadingAnimation->update();
}

void LoadingGameState::draw() {
	Game::getInstance()->getRenderer()->addToQueue(loadingAnimation->getCurrentFrame());
}
