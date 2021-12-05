#pragma once

#include "View.h"

class TileView : public View {
	private:
		bool passable;

	public:
		TileView(Texture* texture, SDL_Rect destrect, bool passable);
		TileView(Texture* texture, bool passable, int x, int y, int sizeMultiplier);

		bool isPassable();
};

