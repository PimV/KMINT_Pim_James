#include "MovingEntity.h"


MovingEntity:: MovingEntity(
	Vector2D position,
	Vector2D velocity,
	double    max_speed,
	double    mass,
	double    turn_rate,
	double    max_force)
	: Entity (position),
	m_vVelocity(velocity),
	m_dMass(mass),
	m_dMaxSpeed(max_speed),
	m_dMaxTurnRate(turn_rate),
	m_dMaxForce(max_force)
{
}



MovingEntity::~MovingEntity(void)
{
}
