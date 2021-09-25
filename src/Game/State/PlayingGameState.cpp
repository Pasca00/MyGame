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

	collisionEngine = new CollisionEngine();
	physicsEngine = new PhysicsEngine(1, 5, 1);
	physicsEngine->attach(player);

	camera = new Camera(player->getRenderRectAddress());

	tiles = std::vector<View*>(1, NULL);
	SDL_Texture* tileTexture = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(),
		"C:/Users/alexp/Desktop/Game/resources/tiles/tile1.png");
	SDL_QueryTexture(tileTexture, NULL, NULL, &(dstrect.w), &(dstrect.h));
	dstrect.w *= 3;
	dstrect.h *= 3;
	dstrect.x = 300;
	dstrect.y = Window::BASE_WINDOW_HEIGHT - dstrect.h;
	tiles[0] = new View(tileTexture, dstrect);
}

void PlayingGameState::enter() { }

void PlayingGameState::handleInput(Game* game, Input* input) {
	if (input->KEY_ESCAPE || input->QUIT) {
		game->setRunning(false);
	}

	if (input->KEY_SPACE) {
		camera->setFocusView(&(tiles[0]->dstrect));
	}

	player->handleInput(input);
}

void PlayingGameState::update() {
	camera->moveToFocus();

	background->update(camera->getXDirection());

	physicsEngine->applyFriction();
	player->update();
	collisionEngine->checkCollision(player, tiles[0]);
}

void PlayingGameState::draw() {
	background->draw();
	player->drawToRelativePosition(camera->getRect());

	camera->renderViewToRelativePosition(tiles[0]);

	SDL_Rect focusZone = camera->getFocusZone();
	focusZone.x -= camera->getRect().x;
	SDL_RenderDrawRect(Game::getInstance()->getRenderer()->getSDLRenderer(), &focusZone);
}