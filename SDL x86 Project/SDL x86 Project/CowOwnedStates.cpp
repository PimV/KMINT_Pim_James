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
	
	cow->followRoute();

	if (cow->onRabbit()) {
		cow->GetFSM()->ChangeState(WanderAround::Instance());
		return;
	}

}


void ChaseRabbit::Exit(Cow* cow)
{
}

//------------------------------------------------------------------------methods for WanderAround
WanderAround* WanderAround::Instance()
{
	static WanderAround instance;

	return &instance;
}


void WanderAround::Enter(Cow* cow)
{
	updateDelay = 100;
	updatesSince = 0;
}


void WanderAround::Execute(Cow* cow)
{
	cow->followRoute();
	if (cow->getRoute()->size() == 0) {
		updatesSince++;
		if (updatesSince > updateDelay) {
			cow->wander();
			updatesSince = 0;
		}
	}
}


void WanderAround::Exit(Cow* cow)
{
}
