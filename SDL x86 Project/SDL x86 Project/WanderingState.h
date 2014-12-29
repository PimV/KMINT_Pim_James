#pragma once
#include "basestate.h"

class WanderingState :
	public BaseState
{
public:
	WanderingState(void);

	virtual void enter(Entity* entity);
	virtual void execute(Entity* entity);
	virtual void exit(Entity* entity);

	static WanderingState* Instance();

	virtual ~WanderingState(void);
};

