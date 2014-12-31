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
}


void FleeFromCow::Execute(Rabbit* rabbit)
{  

}


void FleeFromCow::Exit(Rabbit* rabbit)
{
}
