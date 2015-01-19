#pragma once
#include "Entity.h"
#include <vector>
#include "StateMachine.h"

class Rabbit :
	public Entity
{
public:
	Rabbit(void);

	void draw();
	void update();
	StateMachine<Rabbit>* GetFSM() const { 
		return m_pStateMachine;
	};

	virtual ~Rabbit(void);

private:
	StateMachine<Rabbit>* m_pStateMachine;
};