#include "StateFactory.h"

#include "WanderingState.h"

StateFactory::StateFactory(void)
{
}

BaseState* StateFactory::createState(States state) {
	switch(state) {
	case States::Wandering:
		return new WanderingState();
	case States::Fleeing:
		//return new FleeingState();
	case States::Chasing:
		//return new ChasingState();
	default:
		return nullptr;
	}
}


StateFactory::~StateFactory(void)
{
}
