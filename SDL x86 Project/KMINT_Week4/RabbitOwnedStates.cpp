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

}


void FleeFromCow::Execute(Rabbit* rabbit)
{  


}


void FleeFromCow::Exit(Rabbit* rabbit)
{
}


//------------------------------------------------------------------------methods for WanderAround
RestRabbit* RestRabbit::Instance()
{
	static RestRabbit instance;

	return &instance;
}


void RestRabbit::Enter(Rabbit* rabbit)
{
	updateDelay = 800;
	updatesSince = 0;
}


void RestRabbit::Execute(Rabbit* rabbit)
{
	updatesSince++;
	if (updatesSince > updateDelay) {
		rabbit->GetFSM()->ChangeState(WanderAroundRabbit::Instance());
		return;
	}
}


void RestRabbit::Exit(Rabbit* rabbit)
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

	dre = std::default_random_engine(dev());
	dist1 = std::uniform_int_distribution<int>(0, 100);
}


void WanderAroundRabbit::Execute(Rabbit* rabbit)
{
	
}


void WanderAroundRabbit::Exit(Rabbit* rabbit)
{
}

