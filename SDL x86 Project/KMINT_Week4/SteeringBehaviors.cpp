#include "SteeringBehaviors.h"
#include "MovingEntity.h"


SteeringBehaviors::SteeringBehaviors(void)
{
	this->inWander = true;
	this->inPursuit = false;
	this->inFlee = false;

}

void SteeringBehaviors::setTarget(MovingEntity* e) {
	this->target = e;
}

void SteeringBehaviors::setOrigin(MovingEntity* e) {
	this->origin = e;
}


Vector2D SteeringBehaviors::calculate() {
	Vector2D desired;
	Vector2D steer;

	if (inPursuit && target != nullptr) {
		desired = target->m_vPosition - origin->m_vPosition;

		double d = desired.LengthSq();
		desired.Normalize();

		if (d < 30) {
			if (d < 1) {
				desired *= 0;
			} else {
				desired *= 0.05;
			}			
		} else {
			desired *= origin->m_dMaxSpeed;
		}
		steer = desired - origin->m_vVelocity;
	} else if (inFlee && target != nullptr) {
		Vector2D diff = origin->m_vPosition - target->m_vPosition;
		diff *= origin->m_dMaxSpeed;
		steer = diff - origin->m_vVelocity;
	} else if (inWander) {
		desired = origin->m_vVelocity;
		steer = desired - origin->m_vVelocity;
	}
	return steer;
}

void SteeringBehaviors::setFlee(bool flee) {
	this->inFlee = flee;
	this->inPursuit = false;
	this->inWander = false;
}

void SteeringBehaviors::setWander(bool wander) {
	this->inFlee = false;
	this->inPursuit = false;
	this->inWander = wander;
}

void SteeringBehaviors::setPursuit(bool pursuit) {
	this->inFlee = false;
	this->inPursuit = pursuit;
	this->inWander = false;
}

SteeringBehaviors::~SteeringBehaviors(void)
{
}
