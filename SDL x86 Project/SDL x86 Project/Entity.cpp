#include "Entity.h"
#include <assert.h>


Entity::Entity(void)
{
}

void Entity::setTexture(SDL_Texture* texture) {
	this->texture = texture;
	
}

void Entity::draw() {

}

void Entity::update() {

}

void Entity::setGraph(Graph* graph) {
	this->graph = graph;
}

Graph* Entity::getGraph() {
	return this->graph;
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
