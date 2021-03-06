#pragma once

#include "View.h"

class TileView : public View {
	private:
		bool passable;

	public:
		TileView(SDL_Texture* texture, SDL_Rect destrect, bool passable);
		TileView(SDL_Texture* texture, bool passable, int x, int y, int sizeMultiplier);

		bool isPassable();
};

