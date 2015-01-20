#pragma once
#include "Entity.h"
#include "MovingEntity.h"
#include "StateMachine.h"
#include "SteeringBehaviors.h"
#include <vector>
template <class entity_type> class State;
class Rabbit :
	public MovingEntity
{
public:
	Rabbit(Vector2D position,
		Vector2D velocity,
		double    max_speed,
		double    mass,
		double    turn_rate,
		double    max_force);

	void draw();
	void update(double dt);
	
	SteeringBehaviors* getSteeringMechanism();

	StateMachine<Rabbit>* GetFSM() const { 
		return m_pStateMachine;
	};


	virtual ~Rabbit(void);

private:
	SteeringBehaviors* m_pSteering;
	StateMachine<Rabbit>* m_pStateMachine;


};

