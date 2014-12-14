#include "GraphState.h"
#include "GameStateManager.h"
#include "MySDL.h"

#include "Rabbit.h"
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include <SDL_image.h>
#include "Cow.h"

#include <random>
#include <iostream>

GraphState GraphState::m_GraphState;

GraphState::GraphState(void)
{
}

void GraphState::init(GameStateManager *gsm) {
	rabbitTexture = IMG_LoadTexture(GameStateManager::Instance()->getMySDL()->getRenderer(), "rabbit-3.png");
	cowTexture = IMG_LoadTexture(GameStateManager::Instance()->getMySDL()->getRenderer(), "cow-2.png");

	cow = new Cow();
	rabbit = new Rabbit();
	route = new std::vector<Vertex*>();

	updatesTillRabbitJumps = 100;
	updatesSinceRabbitJump = 0;

	if (cowTexture == NULL) {
		std::cout << "NO cow loaded" << std::endl;
		std::cout << SDL_GetError() << std::endl;
	}

	if (rabbitTexture == NULL) {
		std::cout << "No rabbit img" << std::endl;
	}

	graph = new Graph();

	Vertex* v1 = graph->createRoot(50, 250);

	Vertex* v2 = graph->createVertex(175, 50); v2->setRabbit(true); rabbitVertex = v2; graph->setRabbitVertex(v2); rabbit->setX(v2->getX()); rabbit->setY(v2->getY());
	Vertex* v3 = graph->createVertex(130, 500);

	Vertex* v4 = graph->createVertex(370, 90); 
	Vertex* v5 = graph->createVertex(330, 450); v5->setCow(true); cowVertex = v5; graph->setCowVertex(v5); cow->setX(v5->getX()); cow->setY(v5->getY());

	Vertex* v6 = graph->createVertex(500, 350); 

	Vertex* v7 = graph->createVertex(900, 200);
	Vertex* v8 = graph->createVertex(900, 600);

	Vertex* v9 = graph->createVertex(1200, 400); 

	Vertex* middle = graph->createVertex( 180, 250);



	graph->insertLast(v1); // Root (1(

	graph->insertLast(v2); // Top (2)
	graph->insertLast(v3); // Bot (2)
	graph->insertLast(v4); // Top (3)
	graph->insertLast(v5); // Bot (3)
	graph->insertLast(v6); // cnxn (4)
	graph->insertLast(v7); // Top (5)
	graph->insertLast(v8); // Bot (5)

	graph->insertLast(v9); //End (6)

	graph->linkVertex(v1, v2, 235);
	graph->linkVertex(v1, v3, 262);

	graph->linkVertex(v2, v4, 199);
	graph->linkVertex(v3, v5, 206);

	graph->linkVertex(v4, v6, 290);
	graph->linkVertex(v5, v6, 197);

	graph->linkVertex(v7, v6, 427);
	graph->linkVertex(v8, v6, 471);

	graph->linkVertex(v7, v9, 360);
	graph->linkVertex(v8, v9, 360);
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
		if (mainEvent.button.button == SDL_BUTTON_LEFT) {
			route = graph->AStar(graph->getCowVertex(), graph->getRabbitVertex());
			cow->setRoute(route);
			graph->setCowVertex(route->at(route->size() -1));
		} else if (mainEvent.button.button == SDL_BUTTON_RIGHT) {

		}
		break;
	}
}

void GraphState::update(double dt) 
{
	//cow->setRoute(route);
	cow->update();
	rabbit->update();
	if (route != nullptr) {

		if (route->size() == 0) {
			updatesSinceRabbitJump++;
			if (graph->getCowVertex() == graph->getRabbitVertex() || updatesSinceRabbitJump > updatesTillRabbitJumps) {

				Vertex* newRabbitVertex = nullptr;
				while(newRabbitVertex == nullptr || newRabbitVertex == graph->getCowVertex() || newRabbitVertex == graph->getRabbitVertex()) {
					std::random_device dev;
					std::default_random_engine dre(dev());
					std::uniform_int_distribution<int> dist1(0, graph->getVertices()->size() - 1);

					int index = dist1(dre);
					newRabbitVertex = graph->getVertices()->at(index);
				}
				rabbit->setDestination(newRabbitVertex);
				graph->setRabbitVertex(newRabbitVertex);

				this->rabbitVertex = newRabbitVertex;
				updatesSinceRabbitJump = 0;
			}
		}
	}
}

void GraphState::draw() 
{	

	for(size_t i = 0; i < this->graph->getVertices()->size(); i++) {
		int x = this->graph->getVertices()->at(i)->getX();
		int y = this->graph->getVertices()->at(i)->getY();
		int w = 30;
		int h = 30;

		if (i == 0) {
			GameStateManager::Instance()->getMySDL()->drawRectangle(
				x,
				y,
				w,
				h,
				255, 50, 255);
		} else if(i == this->graph->getVertices()->size() - 1) {
			GameStateManager::Instance()->getMySDL()->drawRectangle(
				x,
				y,
				w,
				h,
				255, 0, 100);
		}else {
			GameStateManager::Instance()->getMySDL()->drawRectangle(
				x,
				y,
				w,
				h,
				255, 50, 0);
		}


	}

	for(size_t i = 0; i < this->graph->getVertices()->size(); i++) {
		for (size_t j = 0; j < this->graph->getVertices()->at(i)->getEdges()->size(); j++) {
			Vertex* child = this->graph->getVertices()->at(i)->getEdges()->at(j)->getChild();
			Vertex* parent = this->graph->getVertices()->at(i)->getEdges()->at(j)->getParent();

			if (child != nullptr && parent != nullptr) {
				int x1 = child->getX() + 30/2;
				int y1 = child->getY()  + 30/2;
				int x2 = parent->getX() + 30/2;
				int y2 = parent->getY() + 30/2;
				GameStateManager::Instance()->getMySDL()->drawLine(x1,y1,x2,y2, 0,255,255);
			}
		}

	}
	cow->draw();
	rabbit->draw();



}

GraphState::~GraphState(void)
{

}