#include "Rabbit.h"
#include "GameStateManager.h"
#include "Vertex.h"

Rabbit::Rabbit(void)
{
	this->setTexture(IMG_LoadTexture(GameStateManager::Instance()->getMySDL()->getRenderer(), "rabbit-3.png"));
}

void Rabbit::draw() {
	SDL_Rect rect;
	rect.x = this->getX();
	rect.y = this->getY();
	rect.w = 30;
	rect.h = 30;
	GameStateManager::Instance()->getMySDL()->drawTexture(this->getTexture(), &rect, NULL);
}

void Rabbit::setDestination(Vertex* destination) {
	if (destination != nullptr) {
		this->setX(destination->getX());
		this->setY(destination->getY());
	}
}

void Rabbit::update() {


}


Rabbit::~Rabbit(void)
{
}
