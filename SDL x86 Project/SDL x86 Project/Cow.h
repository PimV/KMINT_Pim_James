#pragma once
#include "Entity.h"
#include <vector>
class Vertex;
class Cow :
	public Entity
{
public:
	Cow(void);

	void draw();
	void update();

	void setRoute(std::vector<Vertex*>* route);

	virtual ~Cow(void);

private:
	std::vector<Vertex*>* route;
};

