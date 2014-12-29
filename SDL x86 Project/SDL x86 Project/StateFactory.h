#pragma once
#include "States.h"
#include "BaseState.h"
class StateFactory
{
public:
	StateFactory(void);

	static BaseState* createState(States state);

	virtual ~StateFactory(void);
};

