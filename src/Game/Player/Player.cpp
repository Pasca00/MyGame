#include "Player.h"
#include "../Game.h"
#include "../Level/Level.h"
#include "../Physics/TimeEngine.h"
#include "../Visuals/TextureBag/TextureBag.h"

Player::Player(int health, SDL_Rect dstrect, int8_t direction) 
	: Movable(0, 30, 0, 3, 6, DIRECTION_RIGHT, DIRECTION_DOWN) {
	this->health = health;

	this->dstrect = dstrect;

	this->sizeMultiplier = 2;

	this->idleState = new IdlePlayerState();
	this->walkingState = new WalkingPlayerState(this);
	this->fallingState = new FallingPlayerState();
	this->attackState = new AttackPlayerState(this);
	this->currentState_ = idleState;

	//SDL_QueryTexture(currentState_->getCurrentFrame()->texture, NULL, NULL, &this->textureW, &this->textureH);
	this->dstrect.w = textureW * 3;
	this->dstrect.h = textureH * 3;

	healthbar = new Healthbar(this);
}

Player::Player(int health, float x, float y, int8_t direction)
	: Movable(0, 30, 0, 3, 6, direction, DIRECTION_DOWN) {
	this->health = health;

	this->position = glm::vec3(x, y, 0);

	this->sizeMultiplier = 1;

	this->idleState = new IdlePlayerState();
	this->walkingState = new WalkingPlayerState(this);
	this->fallingState = new FallingPlayerState();
	this->attackState = new AttackPlayerState(this);
	this->currentState_ = idleState;


	healthbar = new Healthbar(this);
}

void Player::handleInput(Level* level, Input* input) {
	if (input->KEY_SHIFT) {
		TimeEngine::getInstance()->slowDown();
	} else {
		TimeEngine::getInstance()->returnToNormal();
	}

	currentState_->handleInput(this, input);
}

void Player::update() {
	currentState_->update();
}

void Player::draw() {
	if (xDirection == DIRECTION_RIGHT) {
		Game::getInstance()->getRenderer()->addToQueue(dstrect, currentState_->getCurrentTexture());
	} else {
		Game::getInstance()->getRenderer()->addToQueueFlipped(dstrect, currentState_->getCurrentTexture(), SDL_FLIP_HORIZONTAL);
	}
}

void Player::drawToRelativePosition(Camera* camera) {
	if (xDirection == DIRECTION_RIGHT) {
		glUniform1i(glGetUniformLocation(Game::getInstance()->baseTextureShader->getProgram(), "render_flipped"), 0);
	} else {
		glUniform1i(glGetUniformLocation(Game::getInstance()->baseTextureShader->getProgram(), "render_flipped"), 1);
	}

	camera->drawViewToRelativePosition(currentState_->getCurrentFrame());
	
	//glUniform1i(glGetUniformLocation(Game::getInstance()->baseTextureShader->getProgram(), "render_flipped"), 0);
}

Texture* Player::getCurrentTexture() {
	return currentState_->getCurrentTexture();
}

void Player::setState(PlayerState* state) {
	state->resetAnimation();
	this->currentState_ = state;
}

Player::Healthbar::Healthbar(Player* player) {
	this->player = player;

	this->container = new View(TextureBag::getInstance()->miniTextures["healthbarContainer"], 20, 20, 1.4f);
	this->health = new View(TextureBag::getInstance()->miniTextures["healthbarHealth"], 20, 20, 1.4f);
}

void Player::Healthbar::setHealth(int health) { }

void Player::drawHealthbar() {
	//Game::getInstance()->getRenderer()->addToQueue(healthbar->health);
	Game::getInstance()->getRenderer()->draw(healthbar->container);
}