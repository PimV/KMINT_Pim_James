#include "Weapon.h"
#include "GameStateManager.h"


Weapon::Weapon(void)
{
	this->setTexture(IMG_LoadTexture(GameStateManager::Instance()->getMySDL()->getRenderer(), "gun.png"));
	this->setVisible(true);
}

void Weapon::draw() {
	if (this->visible) {
		SDL_Rect rect;
		rect.x = static_cast<int>(this->getX());
		rect.y = static_cast<int>(this->getY());
		rect.w = 30;
		rect.h = 30;
		GameStateManager::Instance()->getMySDL()->drawTexture(this->getTexture(), &rect, NULL);
	}
}

void Weapon::update() {

}

void Weapon::setVisible(bool visible) {
	this->visible = visible;
}

bool Weapon::getVisible() {
	return this->visible;
}


Weapon::~Weapon(void)
{
}
