#pragma once
class Entity;
class BaseState
{
public:
	BaseState(void);

	virtual void enter(Entity* entity) = 0;
	virtual void execute(Entity* entity) = 0;
	virtual void exit(Entity* entity) = 0;

	virtual ~BaseState(void);
};

