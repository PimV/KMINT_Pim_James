#include "Entity.h"
#include "States.h"
#include <assert.h>


Entity::Entity(void)
{
}

void Entity::setTexture(SDL_Texture* texture) {
	this->texture = texture;
	this->m_pCurrentState = StateFactory::createState(States::Wandering);
}

void Entity::draw() {

}

void Entity::update() {

}

void Entity::changeState(BaseState* state) {
	assert(this->m_pCurrentState && state);

	this->m_pCurrentState->exit(this);
	this->m_pCurrentState = state;
	this->m_pCurrentState->enter(this);

}

BaseState* Entity::getCurrentState() {
	return this->m_pCurrentState;
}

SDL_Texture* Entity::getTexture() {
	return this->texture;
}

double Entity::getX() {
	return this->x;
}

double Entity::getY() {
	return this->y;
}

void Entity::setX(double x) {
	this->x = x;
}

void Entity::setY(double y) {
	this->y = y;
}

Entity::~Entity(void)
{
}
