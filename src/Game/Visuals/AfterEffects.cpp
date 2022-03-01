#include "AfterEffects.h"
#include "../Window/Window.h"
#include "../Game.h"

#include "../glm/gtc/type_ptr.hpp"

AfterEffect::AfterEffect(Shader* shader) {
	this->shader = shader;

	this->size = glm::vec3((float) Window::BASE_WINDOW_WIDTH, (float) Window::BASE_WINDOW_HEIGHT, 0);
	this->position = glm::vec3(0);
}

void AfterEffect::draw() {
	shader->use();
	glUniform2f(shader->getUniformLocation("resolution"), size.x, size.y);
	shader->setTimeUniform((float) Game::getInstance()->getCurrentTime());

	Game::getInstance()->getRenderer()->draw(this);
}