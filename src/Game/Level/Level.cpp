#include "Level.h"

#include "../Physics/PhysicsEngine.h"
#include "../Window/Window.h"

Level::Level(int h, int w) {
	this->tileH = this->tileW = 96;

	this->w = w;
	this->h = h;

	SDL_Rect dstrect;
	dstrect.x = 600;
	dstrect.y = (h - 2) * tileH - 60;

	this->player = new Player(100, dstrect, DIRECTION_RIGHT);
	this->camera = new Camera(player->getRenderRectAddress());
	this->physicsEngine = new PhysicsEngine(1, 5, 1);
	this->collisionEngine = new CollisionEngine();

	physicsEngine->attach(player);

	std::vector<const char*> fileNames(2);
	fileNames[0] = "C:/Users/alexp/Desktop/Game/resources/backgrounds/trees_far.png";
	fileNames[1] = "C:/Users/alexp/Desktop/Game/resources/backgrounds/trees_close.png";
	char* bgFile = "C:/Users/alexp/Desktop/Game/resources/backgrounds/clouds_background.png";

	background = new Background(bgFile, fileNames, 10);

	createTileMap();

	SDL_Texture* shrineTexture = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(),
		"C:/Users/alexp/Desktop/Game/resources/misc/altar.png");
	SDL_QueryTexture(shrineTexture, NULL, NULL, &(dstrect.w), &(dstrect.h));
	dstrect.w *= 4;
	dstrect.h *= 4;
	dstrect.x = Window::BASE_WINDOW_WIDTH * 3;
	dstrect.y = Window::BASE_WINDOW_HEIGHT - tileH - dstrect.h;

	shrine = new InteractableView(player->getRenderRectAddress(), shrineTexture, dstrect);

	std::vector<SDL_Texture*> eKeys(2, NULL);
	eKeys[0] = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(),
		"C:/Users/alexp/Desktop/Game/resources/mini/e_key1.png");
	eKeys[1] = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(),
		"C:/Users/alexp/Desktop/Game/resources/mini/e_key2.png");

	shrine->attachPromptAnimation(new Animation(eKeys, dstrect, 350));
}

void Level::handleInput(Input* input) {
	shrine->onInteract(input);
	player->handleInput(input);
}

void Level::update() {
	camera->moveToFocus();

	background->update(camera->getXDirection());

	shrine->update();

	physicsEngine->applyFriction();
	player->update();
}

void Level::draw() {
	background->draw();
	renderTileMap();

	camera->renderViewToRelativePosition(shrine);
	if (shrine->targetIsInProximity()) {
		camera->renderViewToRelativePosition(shrine->getCurrectPromptFrame());
	}

	player->drawToRelativePosition(camera->getRect());
}

void Level::createTileMap() {
	SDL_Rect dstrect;
	dstrect.w = tileW;
	dstrect.h = tileH;
	dstrect.x = 0;
	dstrect.y = Window::BASE_WINDOW_HEIGHT - tileH;

	SDL_Texture* tileTexture = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(),
		"C:/Users/alexp/Desktop/Game/resources/tiles/tile1.png");

	tiles = std::vector< std::vector<TileView*> >(h, std::vector<TileView*>(w, NULL));

	for (int i = 0; i < w; i++) {
		tiles[0][i] = new TileView(tileTexture, dstrect, false);
		dstrect.x += tileW;
	}
}

void Level::renderTileMap() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (tiles[i][j] != NULL) {
				camera->renderViewToRelativePosition(tiles[i][j]);
			}
		}
	}
}

