#include "WanderingState.h"

WanderingState::WanderingState(void)
{
}

void WanderingState::enter(Entity* entity) {

}

void WanderingState::execute(Entity* entity) {

}

void WanderingState::exit(Entity* entity) {

}

WanderingState* WanderingState::Instance() {
	static WanderingState instance;

	return &instance;
};
WanderingState::~WanderingState(void)
{
}
