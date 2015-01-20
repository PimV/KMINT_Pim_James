#pragma once
#include "Vector2D.h"

class Entity;
class MovingEntity;
class SteeringBehaviors
{


public:
	SteeringBehaviors(void);

	void setTarget(MovingEntity* e);
	void setOrigin(MovingEntity* e);

	void setWander(bool wander);
	void setFlee(bool flee);
	void setPursuit(bool pursuit);

	Vector2D calculate();

	virtual ~SteeringBehaviors(void);
private:
	bool inFlee;
	bool inPursuit;
	bool inWander;

	MovingEntity* origin;
	MovingEntity* target;
};

