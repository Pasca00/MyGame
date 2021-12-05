#include "Renderer.h"
#include "../Game.h"
#include "../glm/gtc/matrix_transform.hpp"

Renderer::Renderer() {
	drawR = 0;
	drawG = 0;
	drawB = 0;

	glClearColor(drawR, drawG, drawB, 1.f);

	std::vector<Vertex> vertices = {
		Vertex(glm::vec3(0.f, 0.f, 0.f), glm::vec3(1), glm::vec2(0.f, 0.f)),
		Vertex(glm::vec3(0.f, 1.f, 0.f), glm::vec3(1), glm::vec2(0.f, 1.f)),
		Vertex(glm::vec3(1.f, 1.f, 0.f), glm::vec3(1), glm::vec2(1.f, 1.f)),
		Vertex(glm::vec3(1.f, 0.f, 0.f), glm::vec3(1), glm::vec2(1.f, 0.f))
	};

	std::vector<unsigned int> indices = {
		0, 1, 2, 3
	};

	quad = new Quad(vertices, indices);

	projectionMatrix = glm::ortho(0.f, (float)Window::BASE_WINDOW_WIDTH, 0.f, (float)Window::BASE_WINDOW_HEIGHT, -0.01f, 10.f);
}

void Renderer::addToQueueFlipped(SDL_Rect dstrect, Texture* texture, SDL_RendererFlip flipType) {
	//SDL_RenderCopyEx(renderer, texture, NULL, &dstrect, 0, NULL, flipType);
}

void Renderer::addToQueue(SDL_Rect dstrect, Texture* texture) {
	//SDL_RenderCopy(renderer, texture, NULL, &dstrect);
}

void Renderer::addToQueue(View* view) {
	//SDL_RenderCopy(renderer, view->texture, NULL, &(view->dstrect));
}

void Renderer::addToQueue(Player* player) {
	//SDL_RenderCopy(renderer, player->getCurrentTexture(), NULL, player->getRectAddress());
}

void Renderer::draw(View* view, Shader* shader) {
	glm::mat4 modelMatrix(1);
	modelMatrix = glm::scale(modelMatrix, glm::vec3(view->texture->getWidth() * view->sizeMultiplier, view->texture->getHeight() * view->sizeMultiplier, 0));

	shader->use();
	shader->setModelMatrix(modelMatrix);
	shader->setProjectionMatrix(projectionMatrix);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, view->texture->getTextureID());

	glBindVertexArray(quad->getVAO());

	glDrawArrays(GL_QUADS, 0, quad->getIndices().size());

	glBindVertexArray(0);
}

void Renderer::clearScreen() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::renderQueue() {
	SDL_RenderPresent(renderer);
}

SDL_Renderer* Renderer::getSDLRenderer() {
	return renderer;
}