#include "../Game.h"
#include "PlayingGameState.h"
#include "../Physics/PhysicsEngine.h"

PlayingGameState::PlayingGameState() : GameState() {	
	std::vector<const char*> fileNames(2);
	fileNames[0] = "C:/Users/alexp/Desktop/Game/resources/backgrounds/trees_far.png";
	fileNames[1] = "C:/Users/alexp/Desktop/Game/resources/backgrounds/trees_close.png";
	char* bgFile = "C:/Users/alexp/Desktop/Game/resources/backgrounds/clouds_background.png";

	background = new Background(bgFile, fileNames, 10);

	SDL_Rect dstrect;
	dstrect.x = 700;
	dstrect.y = Window::BASE_WINDOW_HEIGHT - 200;

	player = new Player(100, dstrect, 1);

	physicsEngine = new PhysicsEngine(1, 5, 1);
	physicsEngine->attach(player);

	camera = new Camera(player->getRenderRectAddress());
}

void PlayingGameState::enter() { }

void PlayingGameState::handleInput(Game* game, Input* input) {
	if (input->KEY_ESCAPE || input->QUIT) {
		game->setRunning(false);
	}

	player->handleInput(input);
}

void PlayingGameState::update() {
	//camera->setFocusView(player->buildRenderRect());
	camera->moveToFocus();

	background->update(camera->getXDirection());

	physicsEngine->applyFriction();
	player->update();
}

void PlayingGameState::draw() {
	background->draw();
	player->drawToRelativePosition(camera->getRect());
}