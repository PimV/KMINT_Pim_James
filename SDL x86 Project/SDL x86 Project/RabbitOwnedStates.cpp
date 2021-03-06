#include "RabbitOwnedStates.h"
#include "Rabbit.h"

//------------------------------------------------------------------------methods for ChaseRabbit
FleeFromCow* FleeFromCow::Instance()
{
	static FleeFromCow instance;

	return &instance;
}


void FleeFromCow::Enter(Rabbit* rabbit)
{
	updateDelay = 50;
	updatesSince = 0;
	fleeUpdates = 1;
	fleeUpdatesDone = 0;
	while(rabbit->getRoute()->size() > 0) {
		rabbit->getRoute()->pop_back();
	}

	rabbit->flee();

}


void FleeFromCow::Execute(Rabbit* rabbit)
{  
	rabbit->followRoute();
	if (rabbit->getRoute()->size() == 0) {
		updatesSince++;
		if (updatesSince > updateDelay) {
			rabbit->flee();
			fleeUpdatesDone++;
			updatesSince = 0;
		}
	}

	if(fleeUpdatesDone > fleeUpdates) {
		rabbit->GetFSM()->ChangeState(WanderAroundRabbit::Instance());
	}
}


void FleeFromCow::Exit(Rabbit* rabbit)
{
}

//------------------------------------------------------------------------methods for WanderAround
WanderAroundRabbit* WanderAroundRabbit::Instance()
{
	static WanderAroundRabbit instance;

	return &instance;
}


void WanderAroundRabbit::Enter(Rabbit* rabbit)
{
	updateDelay = 1200;
	updatesSince = 0;
}


void WanderAroundRabbit::Execute(Rabbit* rabbit)
{

	rabbit->followRoute();
	if (rabbit->getRoute()->size() == 0) {
		updatesSince++;
		if (updatesSince > updateDelay) {
			rabbit->wander();
			updatesSince = 0;
		}
	}
}


void WanderAroundRabbit::Exit(Rabbit* rabbit)
{
}

