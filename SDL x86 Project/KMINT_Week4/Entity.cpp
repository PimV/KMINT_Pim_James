#include "Entity.h"
#include <assert.h>


Entity::Entity(void)
{
}

Entity::Entity(Vector2D pos)
{
	this->m_vPosition = pos;
}

void Entity::setTexture(SDL_Texture* texture) {
	this->texture = texture;
	
}

void Entity::draw() {

}

void Entity::update(double dt) {

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

void Entity::setPosition(double x, double y) {
	this->x = x;
	this->y = y;
}

Entity::~Entity(void)
{
}
