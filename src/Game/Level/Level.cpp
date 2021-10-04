#include "Level.h"

#include "../Physics/PhysicsEngine.h"
#include "../Window/Window.h"

Level::Level(int h, int w) {
	this->tileH = this->tileW = 96;

	this->w = w;
	this->h = h;

	SDL_Rect dstrect;
	dstrect.x = 600;
	dstrect.y = (h - 2) * tileH - 200;

	this->player = new Player(100, dstrect, DIRECTION_RIGHT);
	this->camera = new Camera(player->getRectAddress());
	this->physicsEngine = new PhysicsEngine(6, 20, 1, 1);
	this->collisionEngine = new CollisionEngine();

	physicsEngine->attach(player);

	std::vector<const char*> fileNames(2);
	fileNames[0] = "C:/Users/alexp/Desktop/Game/resources/backgrounds/trees_far.png";
	fileNames[1] = "C:/Users/alexp/Desktop/Game/resources/backgrounds/trees_close.png";
	char* bgFile = "C:/Users/alexp/Desktop/Game/resources/backgrounds/clouds_background.png";

	background = new Background(bgFile, fileNames, 10);

	createTileMap();
	placeDecorations();

	SDL_Texture* shrineTexture = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(),
		"C:/Users/alexp/Desktop/Game/resources/misc/altar.png");
	SDL_QueryTexture(shrineTexture, NULL, NULL, &(dstrect.w), &(dstrect.h));
	dstrect.w *= 4;
	dstrect.h *= 4;
	dstrect.x = 1200;
	dstrect.y = tiles[0][0]->dstrect.y - dstrect.h + 10;

	shrine = new InteractableView(player->getRectAddress(), shrineTexture, dstrect);

	std::vector<SDL_Texture*> eKeys(2, NULL);
	eKeys[0] = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(),
		"C:/Users/alexp/Desktop/Game/resources/mini/e_key1.png");
	eKeys[1] = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(),
		"C:/Users/alexp/Desktop/Game/resources/mini/e_key2.png");

	shrine->attachPromptAnimation(new Animation(eKeys, dstrect, 350));
	shrine->setOnInteractListener([] {
		std::cout << "Deez nuts... haahaa got em\n";
	});
	
}

void Level::handleInput(Input* input) {
	shrine->onInteract(input);
	player->handleInput(input);
}

void Level::update() {
	camera->moveToFocus();

	background->update(camera->getXDirection());

	shrine->update();

	physicsEngine->update();

	collisionEngine->applyPlayerCollisionsOnTiles(player, tiles);

	player->update();
}

void Level::draw() {
	background->draw();
	
	renderDecorations();
	shrine->draw(camera);
	renderTileMap();

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
				tiles[i][j]->draw(camera);
			}
		}
	}
}

void Level::placeDecorations() {
	SDL_Rect dstrect;
	int height = tiles[0][0]->dstrect.y;

	SDL_Texture* fenceTexture = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(),
		"C:/Users/alexp/Desktop/Game/resources/misc/fence.png");
	SDL_QueryTexture(fenceTexture, NULL, NULL, &(dstrect.w), &(dstrect.h));
	dstrect.w *= 5;
	dstrect.h *= 5;
	dstrect.y = height - dstrect.h;
	dstrect.x = 400;
	decorations.push_back(new View(fenceTexture, dstrect));

	SDL_Texture* grassTexture = IMG_LoadTexture(Game::getInstance()->getRenderer()->getSDLRenderer(),
		"C:/Users/alexp/Desktop/Game/resources/misc/grass.png");
	SDL_QueryTexture(fenceTexture, NULL, NULL, &(dstrect.w), &(dstrect.h));
	dstrect.w *= 5;
	dstrect.h *= 5;
	dstrect.y = height - dstrect.h + 20;
	dstrect.x = 0;
	for (int i = 0; i < 20; i++) {
		decorations.push_back(new View(grassTexture, dstrect));
		dstrect.x += dstrect.w;
	}
}

void Level::renderDecorations() {
	for (int i = 0; i < decorations.size(); i++) {
		decorations[i]->draw(camera);
	}
}

