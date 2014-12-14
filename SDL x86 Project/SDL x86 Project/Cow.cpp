#include "Cow.h"
#include "GameStateManager.h"
#include "Vertex.h"

Cow::Cow(void)
{
	this->setTexture(IMG_LoadTexture(GameStateManager::Instance()->getMySDL()->getRenderer(), "cow-2.png"));
	this->route = nullptr;
}

void Cow::draw() {
	SDL_Rect rect;
	rect.x = static_cast<int>(this->getX());
	rect.y = static_cast<int>(this->getY());
	rect.w = 30;
	rect.h = 30;
	GameStateManager::Instance()->getMySDL()->drawTexture(this->getTexture(), &rect, NULL);
}

void Cow::setRoute(std::vector<Vertex*>* route) {
	this->route = route;
}

void Cow::update() {

	if (route != nullptr && !route->empty()) {
		double diffX = abs(this->getX() - route->at(0)->getX());
		double diffY = abs(this->getY() - route->at(0)->getY());

		double mag = sqrt(pow(diffX, 2) + pow(diffY, 2));

		if (this->getX() != route->at(0)->getX()) {
			if (this->getX() > route->at(0)->getX()) {
				this->setX(this->getX() - diffX / mag);
			} else {
				this->setX(this->getX() + diffX / mag);
			}
		}

		if (this->getY() != route->at(0)->getY()) {
			if (this->getY() > route->at(0)->getY()) {
				this->setY(this->getY() - diffY / mag);
			} else {
				this->setY(this->getY() + diffY / mag);
			}
		}


		if (this->getX() > route->at(0)->getX() - 2 && this->getX() < route->at(0)->getX() + 2 && this->getY() > route->at(0)->getY() - 2 && this->getY() < route->at(0)->getY() +2) {
			route->erase(route->begin());
			route->shrink_to_fit();
		}
	}

}

Cow::~Cow(void)
{
}
