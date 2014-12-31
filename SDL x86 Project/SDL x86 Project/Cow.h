#pragma once
#include "Entity.h"
#include "StateMachine.h"
#include "WanderingState.h"
#include <vector>
template <class entity_type> class State;
class Vertex;
class Cow :
	public Entity
{
public:
	Cow(void);

	void draw();
	void update();

	void setRoute(std::vector<Vertex*>* route);
	std::vector<Vertex*>* getRoute();
	//void setGraph(Graph* graph) override;

	//State actions
	void followRoute();
	void chase();
	void wander();

	bool onRabbit();

	StateMachine<Cow>* GetFSM() const { 
		return m_pStateMachine;
	};


	virtual ~Cow(void);

private:
	std::vector<Vertex*>* route;
	Graph* graph;
	StateMachine<Cow>* m_pStateMachine;


};

