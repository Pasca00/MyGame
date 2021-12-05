#include "TextureBag.h"

TextureBag* TextureBag::instance = NULL;

TextureBag::TextureBag() {
	SDL_Renderer* renderer = Game::getInstance()->getRenderer()->getSDLRenderer();
	
	backgroundLayers["backgroundMoon"] = new Texture("C:/Users/alexp/Desktop/Game/resources/backgrounds/clouds_background.png");
	backgroundLayers["backgroundTreesFar"] = new Texture("C:/Users/alexp/Desktop/Game/resources/backgrounds/trees_far.png");
	backgroundLayers["backgroundTreesClose"] = new Texture("C:/Users/alexp/Desktop/Game/resources/backgrounds/trees_close.png");

	
	filters["lightBlueFilter"] = new Texture("C:/Users/alexp/Desktop/Game/resources/filters/blue_filter.png");
	filters["circularMask"] = new Texture("C:/Users/alexp/Desktop/Game/resources/filters/mask.png");

	
	tileTextures["basicTile"] = new Texture("C:/Users/alexp/Desktop/Game/resources/tiles/tile1.png");


	decorationsTextures["woodenFence"] = new Texture("C:/Users/alexp/Desktop/Game/resources/misc/fence.png");
	decorationsTextures["grass"] = new Texture("C:/Users/alexp/Desktop/Game/resources/misc/grass.png");
	decorationsTextures["carriage"] = new Texture("C:/Users/alexp/Desktop/Game/resources/misc/carriage.png");
	decorationsTextures["altar"] = new Texture("C:/Users/alexp/Desktop/Game/resources/misc/altar.png");


	miniTextures["eKeyUp"] = new Texture("C:/Users/alexp/Desktop/Game/resources/mini/e_key1.png");
	miniTextures["eKeyDown"] = new Texture("C:/Users/alexp/Desktop/Game/resources/mini/e_key2.png");
	miniTextures["healthbarContainer"] = new Texture("C:/Users/alexp/Desktop/Game/resources/mini/healthbar/healthbar_container.png");
	miniTextures["healthbarHealth"] = new Texture("C:/Users/alexp/Desktop/Game/resources/mini/healthbar/healthbar_health.png");


	loadPlayerTextures(renderer);
}

void TextureBag::loadPlayerTextures(SDL_Renderer* renderer) {
	std::vector<Texture*> playerIdle(playerIdleFrameCount, NULL);
	std::vector<Texture*> playerWalking(playerWalkingFrameCount, NULL);
	std::vector<Texture*> playerFirstAttack(playerFirstAttackFrameCount, NULL);
	std::vector<Texture*> playerSecondAttack(playerSecondAttackFrameCount, NULL);

	for (int i = 0; i < playerIdleFrameCount; i++) {
		char path[100];
		sprintf(path, "C:/Users/alexp/Desktop/Game/resources/Player/player_idle%d.png", i + 1);
		playerIdle[i] = new Texture(path);
	}
	playerTextures["idle"] = playerIdle;

	for (int i = 0; i < playerWalkingFrameCount; i++) {
		char path[100];
		sprintf(path, "C:/Users/alexp/Desktop/Game/resources/Player/player_walking%d.png", i + 1);
		playerWalking[i] = new Texture(path);
	}
	playerTextures["walking"] = playerWalking;

	for (int i = 0; i < playerFirstAttackFrameCount; i++) {
		char path[100];
		sprintf(path, "C:/Users/alexp/Desktop/Game/resources/Player/player_attack%d.png", i + 1);
		playerFirstAttack[i] = new Texture(path);
	}
	playerTextures["firstAttack"] = playerFirstAttack;

	for (int i = 0; i < playerSecondAttackFrameCount; i++) {
		char path[100];
		sprintf(path, "C:/Users/alexp/Desktop/Game/resources/Player/player_second_attack%d.png", i + 1);
		playerSecondAttack[i] = new Texture(path);
	}
	playerTextures["secondAttack"] = playerSecondAttack;
}

TextureBag* TextureBag::getInstance() {
	if (instance == NULL) {
		instance = new TextureBag();
	}

	return instance;
}


