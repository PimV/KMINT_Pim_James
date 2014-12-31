#pragma once
#include "State.h"
class Entity;
class WanderingState :
	public State<Entity>
{
public:
	WanderingState(void);

	virtual void Enter(Entity* entity);
	virtual void Execute(Entity* entity);
	virtual void Exit(Entity* entity);

	static WanderingState* Instance();

	virtual ~WanderingState(void);
};

