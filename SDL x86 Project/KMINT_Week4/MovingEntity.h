#pragma once
#include "entity.h"
#include "Vector2D.h"

const double maxWidth = 1280;
const double maxHeight = 720;

class MovingEntity :
	public Entity
{
public:

	MovingEntity(
		Vector2D position,
		Vector2D velocity,
		double    max_speed,
		double    mass,
		double    turn_rate,
		double    max_force);
	virtual ~MovingEntity(void);

	Vector2D m_vVelocity;
	//a normalized vector pointing in the direction the entity is heading.
	Vector2D m_vHeading;
	//a vector perpendicular to the heading vector
	Vector2D m_vSide;

	double m_dMass;
	//the maximum speed at which this entity may travel.
	double m_dMaxSpeed;
	//the maximum force this entity can produce to power itself
	//(think rockets and thrust)
	double m_dMaxForce;
	//the maximum rate (radians per second) at which this vehicle can rotate
	double m_dMaxTurnRate;

};

