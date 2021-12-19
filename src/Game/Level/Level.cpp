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

	float x = 600;
	float y = h * tileH + 1;

	this->player = new Player(100, x, y, DIRECTION_RIGHT);
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

	test = new AfterEffect(new Shader("C:/Users/alexp/Desktop/Game/src/Shaders/", std::string("AfterEffectTest")));
	//frameBuffer = new FrameBuffer(new Shader("C:/Users/alexp/Desktop/Game/src/Shaders/", std::string("FrameBufferTest")));
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
	//frameBuffer->bind();

	background->draw();

	renderDecorations();
	renderInteractables();
	
	renderTileMap();
	
	test->draw();

	player->drawToRelativePosition(camera);

	player->drawHealthbar();
}

void Level::createTileMap() {
	int x = 0;
	int y = 0;
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
	Texture* woodenFence = bag_->decorationsTextures["woodenFence"];
	float x = 500;
	float y = tiles[0][0]->pos.y + tileH - 10;
	decorations.push_back(new View(woodenFence, x, y, 5));

	Texture* grass = bag_->decorationsTextures["grass"];
	x = 0;
	for (int i = 0; i < 20; i++) {
		decorations.push_back(new View(grass, x, y, 4));
		x += grass->getWidth() * 4;
	}

	x = 0;
	y = tiles[0][0]->pos.y + tileH - 10;
}

void Level::placeInteractables() {
	float x = 0;
	float y = 0;

	

	x = 1200;
	y = tiles[0][0]->pos.y + tileH - 10;

	InteractableView* shrine = new InteractableView(bag_->decorationsTextures["altar"], x, y, 4);
	shrine->setOnInteractListener([this] {
		printf("deez nuts lmao\n");
	});
	interactables.push_back(shrine);

	x = 0;
	InteractableView* carriage = new InteractableView(bag_->decorationsTextures["carriage"], x, y, 6);
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

