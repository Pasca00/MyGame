#include "MainMenuGameState.h"
#include "../Game.h"

MainMenuGameState::MainMenuGameState() : GameState() {
	Texture* mainMenuWallpaperTexture = new Texture("C:/Users/alexp/Desktop/Game/resources/main_wallpaper.png");

	SDL_Rect dstrect;
	dstrect.x = dstrect.y = 0;
	dstrect.w = Window::BASE_WINDOW_WIDTH;
	dstrect.h = Window::BASE_WINDOW_HEIGHT;

	wallpaperView = new View(mainMenuWallpaperTexture, 0, 0, 3);

	Texture* playButtonTexture = new Texture("C:/Users/alexp/Desktop/Game/resources/play_button.png");

	float y = (float)Window::BASE_WINDOW_HEIGHT / 2 - (playButtonTexture->getHeight() * 2) / 2;
	float x = (float)Window::BASE_WINDOW_WIDTH / 2 - (playButtonTexture->getWidth() * 2) / 2;
	
	playButtonView = new ButtonView(playButtonTexture, x, y, 2);
	playButtonView->setOnHoverListener(
		[this]() {
			
		},
		[this]() {
			
		});

	playButtonView->setOnClickListener(
		[] {
			Game::getInstance()->loadLevel();
		});
}

void MainMenuGameState::handleInput(Game* game, Input* input) {
	if (input->KEY_ESCAPE || input->QUIT || input->KEY_SPACE) {
		game->setRunning(false);

		return;
	}

	if (playButtonView->hasHoverListener()) {
		playButtonView->onHoverRelease();
		if (playButtonView->mouseIsHovering(input->MOUSE_X, input->MOUSE_Y)) {
			playButtonView->onHover();
		}
	}

	if (playButtonView->hasClickListener()) {
		if (playButtonView->mouseIsHovering(input->MOUSE_X, input->MOUSE_Y) && input->LEFT_MOUSE_CLICK) {
			playButtonView->onClick();
		}
	}
}

void MainMenuGameState::draw() {
	Game::getInstance()->getRenderer()->draw(wallpaperView, Game::getInstance()->baseTextureShader);
	Game::getInstance()->getRenderer()->draw(playButtonView, Game::getInstance()->baseTextureShader);
}

void MainMenuGameState::update() { }