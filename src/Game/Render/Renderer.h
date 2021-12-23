#pragma once

#include <vector>
#include <thread>

#include "../Window/Window.h"
#include "../Visuals/Core/Quad.h"
#include "../Visuals/Core/Shader.h"
#include "../Visuals/Core/FrameBuffer.h"
#include "../Visuals/View.h"
#include "../Visuals/AfterEffects.h"
#include "../Player/Player.h"

class Renderer {
	private:
		SDL_Renderer* renderer;
		Uint8 drawR;
		Uint8 drawG;
		Uint8 drawB;

		Quad* quad;
		glm::mat4 projectionMatrix;

	public:
		Renderer();

		void addToQueueFlipped(SDL_Rect dstrect, Texture* texture, SDL_RendererFlip flipType);

		void addToQueue(SDL_Rect dstrect, Texture* texture);
		void addToQueue(View* view);
		void addToQueue(Player* player);

		void draw(View* view, Shader* shader = NULL);
		void draw(Player* player, Shader* shader = NULL);
		void draw(AfterEffect* afterEffect);
		void draw(FrameBuffer* frameBuffer);

		void drawToRelativePosition(View* view, Shader* shader, glm::vec3 cameraPos);
		void drawToRelativePosition(Player* player, Shader* shader, glm::vec3 cameraPos);

		void clearScreen();
		void renderQueue();

		SDL_Renderer* getSDLRenderer();
};

