#pragma once
#include "entity.h"
class Weapon :
	public Entity
{
public:
	Weapon(void);

	void draw();
	void update();

	void setVisible(bool visible);
	bool getVisible();
	virtual ~Weapon(void);
private:
	bool visible;
};

