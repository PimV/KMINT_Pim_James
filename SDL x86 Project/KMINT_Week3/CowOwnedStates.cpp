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
	cow->chase();
}


void ChaseRabbit::Execute(Cow* cow)
{	
	if (cow->onEdge()) {
		cow->chase();
		cow->followRoute();	
	}
	cow->followRoute();	
	
	if (cow->onRabbit()) {
		cow->GetFSM()->ChangeState(WanderAroundCow::Instance());
		return;
	}

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
	cow->followRoute();
	
	if (cow->getRoute()->size() == 0) {
		if (wanderUpdates >= wanderUpdatesRequired) {
			cow->GetFSM()->ChangeState(ChaseRabbit::Instance());
			wanderUpdates = 0;
			return;
		}

		updatesSince++;
		if (updatesSince > updateDelay) {
			cow->wander();
			wanderUpdates++;
			updatesSince = 0;
		}
	}
}


void WanderAroundCow::Exit(Cow* cow)
{
}
