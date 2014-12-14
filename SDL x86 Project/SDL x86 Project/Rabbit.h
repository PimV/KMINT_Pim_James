#pragma once
#include "Entity.h"
#include <vector>
class Vertex;
class Rabbit :
	public Entity
{
public:
	Rabbit(void);

	void draw();
	void update();

	void setDestination(Vertex* destination);

	virtual ~Rabbit(void);

private:
	Vertex* destination;
};