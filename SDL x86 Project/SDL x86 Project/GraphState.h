#pragma once
#include "IGameState.h"

class GameStateManager;
class Graph;
class Vertex;
class Cow;
class Rabbit;
class Weapon;
class GraphState : public IGameState
{
private:
	static GraphState m_GraphState;

	SDL_Texture* cowTexture;
	SDL_Texture* rabbitTexture;

	Cow* cow;
	Rabbit* rabbit;
	Weapon* weapon;
	
	std::vector<Vertex*>* route;

	GameStateManager* gsm;

	Graph* graph;

	Vertex* cowVertex;
	Vertex* rabbitVertex;
	Vertex* weaponVertex;

	int updatesTillRabbitJumps;
	int updatesSinceRabbitJump;

public:
	void init(GameStateManager *gsm);
	void cleanup();

	void pause();
	void resume();

	void handleEvents(SDL_Event mainEvent) ;
	void update(double dt);
	void draw();


	static GraphState* Instance() {
		return &m_GraphState;
	};

	GraphState(void);
	~GraphState(void);
};