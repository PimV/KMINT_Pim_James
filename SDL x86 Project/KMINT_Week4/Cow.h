#pragma once
#include "Entity.h"
#include "MovingEntity.h"
#include "StateMachine.h"
#include <vector>
template <class entity_type> class State;
class Cow :
	public MovingEntity
{
public:
	Cow(	Vector2D position,
		Vector2D velocity,
		double    max_speed,
		double    mass,
		double    turn_rate,
		double    max_force);

	void draw();
	void update();

	StateMachine<Cow>* GetFSM() const { 
		return m_pStateMachine;
	};


	virtual ~Cow(void);

private:
	StateMachine<Cow>* m_pStateMachine;


};

