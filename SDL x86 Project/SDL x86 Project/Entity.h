#pragma once
#include "MySDL.h"
#include "StateFactory.h"
class Graph;
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

	virtual void setGraph(Graph* graph);
	virtual Graph* getGraph();

	void setTexture(SDL_Texture* texture);
	SDL_Texture* getTexture();

	virtual ~Entity(void);
private:
	SDL_Texture* texture;
	double x;
	double y;
protected:
	Graph* graph;
};

