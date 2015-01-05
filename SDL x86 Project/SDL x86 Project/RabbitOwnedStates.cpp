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
	updateDelay = 600;
	updatesSince = 0;
}


void WanderAroundRabbit::Execute(Rabbit* rabbit)
{
	if (rabbit->cowNearby()) {
		if (rabbit->hasWeapon()) {
			rabbit->shootCow();
		} else if(rabbit->weaponNearby()) {
			
			rabbit->GetFSM()->ChangeState(FindWeapon::Instance());
		} else if (rabbit->pillNearby()) {

			//find pill
		} else {
			rabbit->GetFSM()->ChangeState(FleeFromCow::Instance());
			return;
		}
	}

	//if (rabbit->onCow()) {
	//rabbit->GetFSM()->ChangeState(FleeFromCow::Instance());
	//return;
	//	//updatesSince = 0;
	//}

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

//------------------------------------------------------------------------methods for FindWeapon
FindWeapon* FindWeapon::Instance()
{
	static FindWeapon instance;

	return &instance;
}


void FindWeapon::Enter(Rabbit* rabbit)
{
	rabbit->findWeapon();
}


void FindWeapon::Execute(Rabbit* rabbit)
{
	if (rabbit->onWeapon()) {
		rabbit->grabWeapon();
	}

	if (rabbit->hasWeapon()) {
		rabbit->GetFSM()->ChangeState(WanderAroundRabbit::Instance());
		return;
	}

	rabbit->followRoute();
	if (rabbit->getRoute()->size() == 0) {

	}
}


void FindWeapon::Exit(Rabbit* rabbit)
{
}
