#pragma once
#include "State.h"
#include <random>
class Rabbit;

//------------------------------------------------------------------------
//
// Haas zal van de koe wegrennen
//  
//------------------------------------------------------------------------
class FleeFromCow : public State<Rabbit>
{
private:

	FleeFromCow(){}

	//copy ctor and assignment should be private
	FleeFromCow(const FleeFromCow&);
	FleeFromCow& operator=(const FleeFromCow&);

	int updatesSince;
	int updateDelay;

	int fleeUpdates;
	int fleeUpdatesDone;

public:

	//this is a singleton
	static FleeFromCow* Instance();

	virtual void Enter(Rabbit* rabbit);

	virtual void Execute(Rabbit* rabbit);

	virtual void Exit(Rabbit* rabbit);
};

//------------------------------------------------------------------------
//
//  Koe zal achter de haas aan gaan om deze proberen te vangen
//  
//------------------------------------------------------------------------
class RestRabbit : public State<Rabbit>
{
private:

	RestRabbit(){}

	//copy ctor and assignment should be private
	RestRabbit(const RestRabbit&);
	RestRabbit& operator=(const RestRabbit&);

	int updatesSince;
	int updateDelay;

public:

	//this is a singleton
	static RestRabbit* Instance();

	virtual void Enter(Rabbit* rabbit);

	virtual void Execute(Rabbit* rabbit);

	virtual void Exit(Rabbit* rabbit);
};


//------------------------------------------------------------------------
//
//  Koe zal achter de haas aan gaan om deze proberen te vangen
//  
//------------------------------------------------------------------------
class WanderAroundRabbit : public State<Rabbit>
{
private:

	WanderAroundRabbit(){}

	//copy ctor and assignment should be private
	WanderAroundRabbit(const WanderAroundRabbit&);
	WanderAroundRabbit& operator=(const WanderAroundRabbit&);

	int updatesSince;
	int updateDelay;
	int actionId;
	std::random_device dev;
	std::default_random_engine dre;//(dev());
	std::uniform_int_distribution<int> dist1;//(0, 100);

public:

	//this is a singleton
	static WanderAroundRabbit* Instance();

	virtual void Enter(Rabbit* rabbit);

	virtual void Execute(Rabbit* rabbit);

	virtual void Exit(Rabbit* rabbit);
};


