#pragma once
#include "entity.h"
#include "Vector2D.h"
class MovingEntity :
	public Entity
{
public:
	
  MovingEntity(Vector2D position,
               Vector2D velocity,
               double    max_speed,
               double    mass,
               double    turn_rate,
               double    max_force);
	virtual ~MovingEntity(void);
protected:
	Vector2D m_vVelocity;

	Vector2D m_vSide;

	double mass;
	double maxSpeed;
	double maxForce;

	double maxTurnRate;
};

