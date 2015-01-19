#include "GraphState.h"
#include "GameStateManager.h"
#include "MySDL.h"

#include "Rabbit.h"
#include <SDL_image.h>
#include "Cow.h"

#include "CowOwnedStates.h"

#include <random>
#include <iostream>

GraphState GraphState::m_GraphState;

GraphState::GraphState(void)
{
}

void GraphState::init(GameStateManager *gsm) {
	rabbitTexture = IMG_LoadTexture(GameStateManager::Instance()->getMySDL()->getRenderer(), "rabbit-3.png");
	cowTexture = IMG_LoadTexture(GameStateManager::Instance()->getMySDL()->getRenderer(), "cow-2.png");



	if (cowTexture == NULL) {
		std::cout << "NO cow loaded" << std::endl;
		std::cout << SDL_GetError() << std::endl;
	}

	if (rabbitTexture == NULL) {
		std::cout << "No rabbit img" << std::endl;
	}
}

void GraphState::cleanup() 
{
}

void GraphState::pause() 
{
}

void GraphState::resume() 
{
}

void GraphState::handleEvents(SDL_Event mainEvent) 
{	
	int x,y;
	switch(mainEvent.type) {
	case SDL_MOUSEBUTTONDOWN:
		SDL_GetMouseState(&x, &y);
		break;
	}
}

void GraphState::update(double dt) 
{
}

void GraphState::draw() 
{
}

GraphState::~GraphState(void)
{

}