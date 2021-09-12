#include "PlayingGameState.h"
#include "../Game.h"

PlayingGameState::PlayingGameState() : GameState() {

	SDL_Texture* backgroundTexture = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(),
		"C:/Users/alexp/Desktop/Game/resources/backgrounds/clouds_background.png");
	
	SDL_Rect dstrect;
	dstrect.x = dstrect.y = 0;
	dstrect.w = Window::BASE_WINDOW_WIDTH;
	dstrect.h = Window::BASE_WINDOW_HEIGHT;

	background = new View(backgroundTexture, dstrect);

	SDL_Texture* treesFarTexture = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(),
		"C:/Users/alexp/Desktop/Game/resources/backgrounds/trees_far.png");

	treesFar = std::vector<View*>(20, NULL);
	treesClose = std::vector<View*>(20, NULL);

	for (int i = 0; i < 20; i++) {
		treesFar[i] = new View(treesFarTexture, dstrect);
		//treesClose[i] = new View(treesCloseTexture, dstrect);
		dstrect.x += dstrect.w;
	}

	dstrect.x = 400;
	dstrect.y = 200;

	player = new Player(100, dstrect, 1);
}

void PlayingGameState::enter() { }

void PlayingGameState::handleInput(Game* game, Input* input) {
	if (input->KEY_ESCAPE || input->QUIT) {
		game->setRunning(false);
	}

	player->handleInput(input);
}

void PlayingGameState::update() {
	player->update();
}

void PlayingGameState::draw() {
	Game::getInstance()->getRenderer()->addToQueue(background);

	Game::getInstance()->getRenderer()->addToQueue(treesFar[0]);

	player->draw();
}