#pragma once
#include "Entity.h"
#include "StateMachine.h"
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
	void setDestination(Vertex* destination);
	//void setGraph(Graph* graph) override;

	//State actions
	void followRoute();
	void chase();
	void wander();

	bool onEdge();
	void decreaseRoute();

	bool onRabbit();

	StateMachine<Cow>* GetFSM() const { 
		return m_pStateMachine;
	};


	virtual ~Cow(void);

private:
	std::vector<Vertex*>* route;
	StateMachine<Cow>* m_pStateMachine;


};

