#pragma once
#include "Entity.h"
#include <vector>

class Vertex;
class Rabbit :
	public Entity
{
public:
	Rabbit(void);

	void draw();
	void update();

	void setDestination(Vertex* destination);

	virtual ~Rabbit(void);

private:
	Vertex* destination;
	/*StateMachine<Entity>* m_pStateMachine;
	StateMachine<Entity>* GetFSM()const{ return m_pStateMachine; }*/
};