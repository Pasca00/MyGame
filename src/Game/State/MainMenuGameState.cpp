#include "MainMenuGameState.h"
#include "../Game.h"

MainMenuGameState::MainMenuGameState(Renderer* renderer) : GameState() {
	SDL_Texture* mainMenuWallpaperTexture = IMG_LoadTexture(renderer->getSDLRenderer(), "C:/Users/alexp/Desktop/Game/resources/main_wallpaper.png");

	SDL_Rect dstrect;
	dstrect.x = dstrect.y = 0;
	dstrect.w = Window::BASE_WINDOW_WIDTH;
	dstrect.h = Window::BASE_WINDOW_HEIGHT;

	wallpaperView = new View(mainMenuWallpaperTexture, dstrect);

	SDL_Texture* playButtonTexture = IMG_LoadTexture(renderer->getSDLRenderer(), "C:/Users/alexp/Desktop/Game/resources/play_button.png");
	
	std::cout << SDL_GetError() << std::endl;

	SDL_QueryTexture(playButtonTexture, NULL, NULL, &(dstrect.w), &(dstrect.h));
	dstrect.w *= 2;
	dstrect.h *= 2;
	dstrect.y = Window::BASE_WINDOW_HEIGHT / 2 - dstrect.h / 2;
	dstrect.x = Window::BASE_WINDOW_WIDTH / 2 - dstrect.w / 2;

	playButtonView = new ButtonView(playButtonTexture, dstrect);
	playButtonView->setOnHoverListener(
		[this]() {
			SDL_SetTextureColorMod(playButtonView->texture, 150, 150, 150);
		},
		[this]() {
			SDL_SetTextureColorMod(playButtonView->texture, 255, 255, 255);
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
	Game::getInstance()->getRenderer()->addToQueue(wallpaperView);
	Game::getInstance()->getRenderer()->addToQueue(playButtonView);
}

void MainMenuGameState::update() { }