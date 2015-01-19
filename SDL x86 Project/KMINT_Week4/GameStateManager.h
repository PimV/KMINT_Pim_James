#pragma once
#include <vector>

class IGameState;
class MySDL;
class GameStateManager
{
public:
	GameStateManager();

	void init();
	void cleanup();

	void changeGameState(IGameState* gameState);
	void pushGameState(IGameState* gameState);
	void popState();

	void handleEvents();
	void update(double dt);
	void draw();

	bool isRunning();
	void quit();

	MySDL* getMySDL();

	//Singleton
	static GameStateManager* Instance() {
		return &s_gsm;
	};

	virtual ~GameStateManager();

private:
	std::vector<IGameState*> states;
	bool running;
	MySDL* mySDL;

	static GameStateManager s_gsm;
};

