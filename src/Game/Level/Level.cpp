#include "Level.h"

#include "../Physics/PhysicsEngine.h"
#include "../Physics/TimeEngine.h"
#include "../Window/Window.h"
#include "../Visuals/TextureBag/TextureBag.h"

Level::Level(int h, int w) {
	bag_ = TextureBag::getInstance();

	this->tileH = this->tileW = 96;

	this->w = w;
	this->h = h;

	SDL_Rect dstrect;
	dstrect.x = 600;
	dstrect.y = (h - 2) * tileH - 200;

	this->player = new Player(100, dstrect, DIRECTION_RIGHT);
	this->camera = new Camera(player->getRectAddress(), 0, w * tileW);
	this->timeEngine = TimeEngine::getInstance();
	this->physicsEngine = new PhysicsEngine(2, 20, 1, 1, timeEngine->getPhysicsMultilpierAddress());
	this->collisionEngine = new CollisionEngine(0, w * tileW);
	
	physicsEngine->attach(player);

	std::vector<const char*> fileNames(2);
	fileNames[0] = "C:/Users/alexp/Desktop/Game/resources/backgrounds/trees_far.png";
	fileNames[1] = "C:/Users/alexp/Desktop/Game/resources/backgrounds/trees_close.png";
	char* bgFile = "C:/Users/alexp/Desktop/Game/resources/backgrounds/clouds_background.png";

	background = new Background(bgFile, fileNames, 10);

	createTileMap();
	placeDecorations();
	placeInteractables();

	lightBlueFilter = new Filter(bag_->filters["lightBlueFilter"], SDL_BLENDMODE_MUL);
	mask = new Filter(bag_->filters["circularMask"], SDL_BLENDMODE_MOD);
}

void Level::handleInput(Input* input) {
	feedInputToInteractables(input);
	player->handleInput(this, input);
}

void Level::update() {

	background->update(camera->getXDirection());

	updateInteractables();

	collisionEngine->applyPlayerCollisionsOnTiles(player, tiles);

	physicsEngine->update();

	camera->moveToFocus();

	player->update();
}

void Level::draw() {
	background->draw();
	
	renderDecorations();
	renderInteractables();
	renderTileMap();

	lightBlueFilter->draw(camera);
	mask->draw(camera);

	player->drawToRelativePosition(camera->getRect());

	player->drawHealthbar();
}

void Level::createTileMap() {
	int x = 0;
	int y = Window::BASE_WINDOW_HEIGHT - tileH;
	tiles = std::vector< std::vector<TileView*> >(h, std::vector<TileView*>(w, NULL));

	for (int i = 0; i < w; i++) {
		tiles[0][i] = new TileView(bag_->tileTextures["basicTile"], false, x, y, 3);
		x += tileW;
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
	SDL_Rect rect;

	SDL_Texture* woodenFence = bag_->decorationsTextures["woodenFence"];
	SDL_QueryTexture(woodenFence, NULL, NULL, &rect.w, &rect.h);
	rect.w *= 5;
	rect.h *= 5;
	rect.y = tiles[0][0]->dstrect.y - rect.h + 10;
	rect.x = 500;
	decorations.push_back(new View(woodenFence, rect));

	SDL_Texture* grass = bag_->decorationsTextures["grass"];
	SDL_QueryTexture(grass, NULL, NULL, &rect.w, &rect.h);
	rect.w *= 4;
	rect.h *= 4;
	rect.y = tiles[0][0]->dstrect.y - rect.h + 10;
	rect.x = 0;

	for (int i = 0; i < 20; i++) {
		decorations.push_back(new View(grass, rect));
		rect.x += rect.w;
	}
}

void Level::placeInteractables() {
	int x = 0;
	int y = 0;

	std::vector<SDL_Texture*> eKeys{
		bag_->miniTextures["eKeyUp"],
		bag_->miniTextures["eKeyDown"]
	};

	x = 1200;
	y = tiles[0][0]->dstrect.y;

	InteractableView* shrine = new InteractableView(player->getRectAddress(), bag_->decorationsTextures["altar"], x, y, 4);
	shrine->attachPromptAnimation(new Animation(eKeys, {0, 0, 0, 0}, 350));
	shrine->setOnInteractListener([this] {
		printf("deez nuts lmao\n");
	});
	interactables.push_back(shrine);

	x = 0;
	y = tiles[0][0]->dstrect.y;

	InteractableView* carriage = new InteractableView(player->getRectAddress(), bag_->decorationsTextures["carriage"], x, y, 6);
	carriage->attachPromptAnimation(new Animation(eKeys, {0, 0, 0, 0}, 350));
	carriage->setOnInteractListener([] {
		printf("add Money\n");
	});
	
	interactables.push_back(carriage);
}

void Level::renderDecorations() {
	for (int i = 0; i < decorations.size(); i++) {
		decorations[i]->draw(camera);
	}
}

void Level::renderInteractables() {
	for (int i = 0; i < interactables.size(); i++) {
		interactables[i]->draw(camera);
	}
}

void Level::updateInteractables() {
	for (int i = 0; i < interactables.size(); i++) {
		interactables[i]->update();
	}
}

void Level::feedInputToInteractables(Input* input) {
	for (int i = 0; i < interactables.size(); i++) {
		interactables[i]->onInteract(input);
	}
}

