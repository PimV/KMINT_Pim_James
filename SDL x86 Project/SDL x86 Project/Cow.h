#pragma once
#include "Entity.h"
#include <vector>
#include "StateMachine.h"
#include "WanderingState.h"
class Vertex;
class Cow :
	public Entity
{
public:
	Cow(void) {
		m_pStateMachine = new StateMachine<Cow>(this);
		m_pStateMachine->SetCurrentState(WanderingState::Instance());
		m_pStateMachine->SetGlobalState(WanderingState::Instance());
	};

	void draw();
	void update();

	void setRoute(std::vector<Vertex*>* route);

	virtual ~Cow(void);

private:
	std::vector<Vertex*>* route;
	StateMachine<Cow>* m_pStateMachine;

};

