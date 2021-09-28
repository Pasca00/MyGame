#pragma once

#include "../Player/Player.h"
#include "../Render/Camera.h"
#include "../Physics/CollisionEngine.h"
#include "../Visuals/Background.h"
#include "../Input/InputCollector.h"
#include "../Visuals/TileView.h"
#include "../Visuals/InteractableView.h"

class PhysicsEngine;

class Level {
	private:
		int tileW;
		int tileH;

		int w;		// Level width in tiles
		int h;		// Level height in tiles

		Player* player;
		
		Camera* camera;
		PhysicsEngine* physicsEngine;
		CollisionEngine* collisionEngine;

		Background* background;

		std::vector< std::vector<TileView*> > tiles;

		InteractableView* shrine;

		std::vector<View*> decorations;

		void createTileMap();
		void renderTileMap();
		void placeDecorations();
		void renderDecorations();

	public:
		Level(int w, int h);

		void handleInput(Input* input);
		void update();
		void draw();

};

