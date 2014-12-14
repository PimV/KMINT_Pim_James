#pragma once
#include "MySDL.h"
class Entity
{
public:
	Entity(void);

	virtual void update();
	virtual void draw();

	double getX();
	double getY();
	void setX(double x);
	void setY(double y);

	void setTexture(SDL_Texture* texture);
	SDL_Texture* getTexture();

	virtual ~Entity(void);
private:
	SDL_Texture* texture;
	double x;
	double y;
};

