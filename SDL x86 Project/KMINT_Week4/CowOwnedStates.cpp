#include "CowOwnedStates.h"
#include "Cow.h"
#include <random>
#include <iostream>

//------------------------------------------------------------------------methods for ChaseRabbit
ChaseRabbit* ChaseRabbit::Instance()
{
	static ChaseRabbit instance;

	return &instance;
}


void ChaseRabbit::Enter(Cow* cow)
{
}


void ChaseRabbit::Execute(Cow* cow)
{	

}


void ChaseRabbit::Exit(Cow* cow)
{
}

//------------------------------------------------------------------------methods for WanderAround
WanderAroundCow* WanderAroundCow::Instance()
{
	static WanderAroundCow instance;

	return &instance;
}


void WanderAroundCow::Enter(Cow* cow)
{
	updateDelay = 100;
	updatesSince = 0;
	wanderUpdates = 0;

	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 6);
	wanderUpdatesRequired = dist1(dre);
}


void WanderAroundCow::Execute(Cow* cow)
{

}


void WanderAroundCow::Exit(Cow* cow)
{
}
