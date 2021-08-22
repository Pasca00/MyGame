#include "MainMenuGameState.h"
#include "../Game.h"

MainMenuGameState::MainMenuGameState(Renderer* renderer) : GameState() {
	wallpaperView = new View(renderer->getSDLRenderer(), "C:/Users/alexp/Desktop/Game/resources/main_wallpaper.png");
}

void MainMenuGameState::handleInput(Game* game, Input* input) {
	if (input->KEY_ESCAPE || input->QUIT || input->KEY_SPACE) {
		game->setRunning(false);
	}
}

void MainMenuGameState::draw() {
	Game::getInstance()->getRenderer()->addToQueue(wallpaperView->texture);
}