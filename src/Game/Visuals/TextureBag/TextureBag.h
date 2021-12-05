#pragma once

#include <unordered_map>
#include "../../Game.h"


class TextureBag {
	private:
		SDL_mutex* mtx;
		//std::mutex mtx;

		static TextureBag* instance;
		TextureBag();

		Uint8 playerIdleFrameCount = 6;
		Uint8 playerWalkingFrameCount = 7;
		Uint8 playerFirstAttackFrameCount = 5;
		Uint8 playerSecondAttackFrameCount = 3;
		void loadPlayerTextures(SDL_Renderer* renderer);

	public:
		static TextureBag* getInstance();

		std::unordered_map<std::string, Texture*> backgroundLayers;

		std::unordered_map<std::string, Texture*> tileTextures;

		std::unordered_map<std::string, std::vector<Texture*>> playerTextures;

		std::unordered_map<std::string, Texture*> miniTextures;

		std::unordered_map<std::string, Texture*> decorationsTextures;

		std::unordered_map<std::string, Texture*> enemyTextures;

		std::unordered_map<std::string, Texture*> filters;
};

