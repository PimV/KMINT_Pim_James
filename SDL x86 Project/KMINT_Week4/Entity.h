#pragma once
#include "MySDL.h"
#include "StateFactory.h"
#include "Vector2D.h"
class Entity
{
public:
	Entity(void);
	Entity(Vector2D pos);

	virtual void update();
	virtual void draw();

	double getX();
	double getY();
	void setX(double x);
	void setY(double y);
	void setPosition(double x, double y);

	void setTexture(SDL_Texture* texture);
	SDL_Texture* getTexture();

	virtual ~Entity(void);
private:
	SDL_Texture* texture;
	double x;
	double y;

	
protected:
	Vector2D m_vPosition;
};

