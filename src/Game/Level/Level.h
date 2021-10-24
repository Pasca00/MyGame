#pragma once

#include "../Player/Player.h"
#include "../Render/Camera.h"
#include "../Physics/CollisionEngine.h"
#include "../Input/InputCollector.h"
#include "../Visuals/Background.h"
#include "../Visuals/TileView.h"
#include "../Visuals/InteractableView.h"
#include "../Visuals/Filter.h"

class PhysicsEngine;
class TimeEngine;

class Level {
	private:
		int tileW;
		int tileH;

		int w;		// Level width in tiles
		int h;		// Level height in tiles

		Player* player;
		
		Camera* camera;
		PhysicsEngine* physicsEngine;
		TimeEngine* timeEngine;
		CollisionEngine* collisionEngine;

		Background* background;

		std::vector< std::vector<TileView*> > tiles;

		std::vector<InteractableView*> interactables;
		std::vector<View*> decorations;

		Animation* iceWraith;

		void createTileMap();
		void renderTileMap();
		void placeDecorations();
		void placeInteractables();
		void renderDecorations();
		void renderInteractables();

		void updateInteractables();
		void feedInputToInteractables(Input* input);

	public:
		Filter* lightBlueFilter;
		Filter* mask;

		Level(int w, int h);

		void handleInput(Input* input);
		void update();
		void draw();
};

