#pragma once
class GameStateManager;
class Main
{
public:
	Main(void);
	void runLoop(GameStateManager* gsm);
	~Main(void);
};

