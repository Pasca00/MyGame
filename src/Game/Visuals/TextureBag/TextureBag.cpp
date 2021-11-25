#include "TextureBag.h"

TextureBag* TextureBag::instance = NULL;

TextureBag::TextureBag() {
	SDL_Renderer* renderer = Game::getInstance()->getRenderer()->getSDLRenderer();

	mtx = SDL_CreateMutex();
	
	SDL_LockMutex(mtx);
	backgroundLayers["backgroundMoon"] = IMG_LoadTexture(renderer, "C:/Users/alexp/Desktop/Game/resources/backgrounds/clouds_background.png");
	backgroundLayers["backgroundTreesFar"] = IMG_LoadTexture(renderer, "C:/Users/alexp/Desktop/Game/resources/backgrounds/trees_far.png");
	backgroundLayers["backgroundTreesClose"] = IMG_LoadTexture(renderer, "C:/Users/alexp/Desktop/Game/resources/backgrounds/trees_close.png");
	SDL_UnlockMutex(mtx);

	SDL_LockMutex(mtx);
	filters["lightBlueFilter"] = IMG_LoadTexture(renderer, "C:/Users/alexp/Desktop/Game/resources/filters/blue_filter.png");
	filters["circularMask"] = IMG_LoadTexture(renderer, "C:/Users/alexp/Desktop/Game/resources/filters/mask.png");
	SDL_UnlockMutex(mtx);

	SDL_LockMutex(mtx);
	tileTextures["basicTile"] = IMG_LoadTexture(renderer, "C:/Users/alexp/Desktop/Game/resources/tiles/tile1.png");
	SDL_UnlockMutex(mtx);

	SDL_LockMutex(mtx);
	decorationsTextures["woodenFence"] = IMG_LoadTexture(renderer, "C:/Users/alexp/Desktop/Game/resources/misc/fence.png");
	decorationsTextures["grass"] = IMG_LoadTexture(renderer, "C:/Users/alexp/Desktop/Game/resources/misc/grass.png");
	decorationsTextures["carriage"] = IMG_LoadTexture(renderer, "C:/Users/alexp/Desktop/Game/resources/misc/carriage.png");
	decorationsTextures["altar"] = IMG_LoadTexture(renderer, "C:/Users/alexp/Desktop/Game/resources/misc/altar.png");
	SDL_UnlockMutex(mtx);

	SDL_LockMutex(mtx);
	miniTextures["eKeyUp"] = IMG_LoadTexture(renderer, "C:/Users/alexp/Desktop/Game/resources/mini/e_key1.png");
	miniTextures["eKeyDown"] = IMG_LoadTexture(renderer, "C:/Users/alexp/Desktop/Game/resources/mini/e_key2.png");
	miniTextures["healthbarContainer"] = IMG_LoadTexture(renderer, "C:/Users/alexp/Desktop/Game/resources/mini/healthbar/healthbar_container.png");
	miniTextures["healthbarHealth"] = IMG_LoadTexture(renderer, "C:/Users/alexp/Desktop/Game/resources/mini/healthbar/healthbar_health.png");
	SDL_UnlockMutex(mtx);

	SDL_LockMutex(mtx);
	loadPlayerTextures(renderer);
	SDL_UnlockMutex(mtx);
}

void TextureBag::loadPlayerTextures(SDL_Renderer* renderer) {
	std::vector<SDL_Texture*> playerIdle(playerIdleFrameCount, NULL);
	std::vector<SDL_Texture*> playerWalking(playerWalkingFrameCount, NULL);
	std::vector<SDL_Texture*> playerFirstAttack(playerFirstAttackFrameCount, NULL);
	std::vector<SDL_Texture*> playerSecondAttack(playerSecondAttackFrameCount, NULL);

	for (int i = 0; i < playerIdleFrameCount; i++) {
		char path[100];
		sprintf(path, "C:/Users/alexp/Desktop/Game/resources/Player/player_idle%d.png", i + 1);
		playerIdle[i] = IMG_LoadTexture(renderer, path);
	}
	playerTextures["idle"] = playerIdle;

	for (int i = 0; i < playerWalkingFrameCount; i++) {
		char path[100];
		sprintf(path, "C:/Users/alexp/Desktop/Game/resources/Player/player_walking%d.png", i + 1);
		playerWalking[i] = IMG_LoadTexture(renderer, path);
	}
	playerTextures["walking"] = playerWalking;

	for (int i = 0; i < playerFirstAttackFrameCount; i++) {
		char path[100];
		sprintf(path, "C:/Users/alexp/Desktop/Game/resources/Player/player_attack%d.png", i + 1);
		playerFirstAttack[i] = IMG_LoadTexture(renderer, path);
	}
	playerTextures["firstAttack"] = playerFirstAttack;

	for (int i = 0; i < playerSecondAttackFrameCount; i++) {
		char path[100];
		sprintf(path, "C:/Users/alexp/Desktop/Game/resources/Player/player_second_attack%d.png", i + 1);
		playerSecondAttack[i] = IMG_LoadTexture(renderer, path);
	}
	playerTextures["secondAttack"] = playerSecondAttack;
}

TextureBag* TextureBag::getInstance() {
	if (instance == NULL) {
		instance = new TextureBag();
	}

	return instance;
}


