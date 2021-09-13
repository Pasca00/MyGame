#pragma once

#include <vector>
#include "View.h"

class Background {
	private:
		View* staticBackground;
		std::vector<std::vector<View*>> parallaxLayers;
		int baseScrollSpeed;

	public:
		Background(const char* backgroundTextureFile, std::vector<const char*> layerTexturesFiles, int numberOfScenes);
		void setBaseScrollSpeed(int baseScrollSpeed);
		void scrollLeft();
		void scrollRight();

		void draw();
};

