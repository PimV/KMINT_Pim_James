#include "WanderingState.h"
#include "Entity.h"
#include <iostream>

WanderingState::WanderingState(void)
{
}

void WanderingState::Enter(Entity* entity) {

}

void WanderingState::Execute(Entity* entity) {
	
}

void WanderingState::Exit(Entity* entity) {

}

WanderingState* WanderingState::Instance() {
	static WanderingState instance;

	return &instance;
}

WanderingState::~WanderingState(void)
{
}
