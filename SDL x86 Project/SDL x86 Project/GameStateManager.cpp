#include "GameStateManager.h"
#include "IGameState.h"
#include "GraphState.h"
#include "MySDL.h"

GameStateManager GameStateManager::s_gsm;
GameStateManager::GameStateManager(void)
{
}

void GameStateManager::init() {
	mySDL = new MySDL();
	mySDL->init();
	GameStateManager::Instance()->changeGameState(GraphState::Instance());
}

void GameStateManager::cleanup() {
	//While there are states on the stack, clean them up
	while (!states.empty()) {
		//Peek at top state and clean that state
		states.back()->cleanup();

		//Remove top state
		states.pop_back();
	}
}

void GameStateManager::changeGameState(IGameState* gameState) {
	if (!states.empty()) {
		states.back()->cleanup();
		states.pop_back();
	}

	states.push_back(gameState);
	states.back()->init(GameStateManager::Instance());
}

void GameStateManager::pushGameState(IGameState* gameState) {
	if (!states.empty()) {
		states.back()->pause();
	}

	states.push_back(gameState);
	states.back()->init(GameStateManager::Instance());
}

void GameStateManager::popState() {
	if (!states.empty()) {
		states.back()->cleanup();
		states.pop_back();
	}

	if (!states.empty()) {
		states.back()->resume();
	}
}

void GameStateManager::handleEvents() {
	SDL_Event mainEvent;

	while(SDL_PollEvent(&mainEvent)) 
	{
		switch(mainEvent.type) 
		{
		case SDL_QUIT:
			exit(0);
			break;
		case SDL_KEYDOWN:
			switch(mainEvent.key.keysym.sym) 
			{
			default: 
				states.back()->handleEvents(mainEvent);
				break;
			}
			break;
		case SDL_KEYUP:
			switch(mainEvent.key.keysym.sym) {
			default:
				states.back()->handleEvents(mainEvent);
				break;
			}
			break;
		default:
			states.back()->handleEvents(mainEvent);
			break;
		}
	}



}

void GameStateManager::update(double deltaTime) {
	states.back()->update(deltaTime);
}

void GameStateManager::draw() {
	mySDL->clearScreen();

	states.back()->draw();

	mySDL->drawScreen();

}


void GameStateManager::quit() {
	SDL_Quit();
}

MySDL* GameStateManager::getMySDL() {
	return this->mySDL;
}


GameStateManager::~GameStateManager(void)
{
}
