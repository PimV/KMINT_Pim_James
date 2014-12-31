#include "Cow.h"
#include "GameStateManager.h"
#include "Vertex.h"
#include "CowOwnedStates.h"
#include "Graph.h"
#include "Edge.h"
#include <random>

Cow::Cow(void)
{
	this->setTexture(IMG_LoadTexture(GameStateManager::Instance()->getMySDL()->getRenderer(), "cow-2.png"));
	this->route = new std::vector<Vertex*>();
	this->graph = nullptr;

	m_pStateMachine = new StateMachine<Cow>(this);
	m_pStateMachine->SetCurrentState(WanderAround::Instance());
}

void Cow::draw() {
	SDL_Rect rect;
	rect.x = static_cast<int>(this->getX());
	rect.y = static_cast<int>(this->getY());
	rect.w = 30;
	rect.h = 30;
	GameStateManager::Instance()->getMySDL()->drawTexture(this->getTexture(), &rect, NULL);
	GameStateManager::Instance()->getMySDL()->drawText(this->GetFSM()->GetNameOfCurrentState(), this->getX() - 15, this->getY() - 30, 100, 16);
}

void Cow::setRoute(std::vector<Vertex*>* route) {
	this->route = route;
}

std::vector<Vertex*>* Cow::getRoute() {
	return this->route;
}

void Cow::setGraph(Graph* graph) {
	this->graph = graph;
}

bool Cow::onRabbit() {
	if (route == nullptr) {
		return false;
	}

	if (route->size() == 0) {
		return true;
	}

	return false;


	return false;
}

void Cow::followRoute() {
	/*if (route->size() == 0) {
	route = graph->getRouteToRabbit();
	graph->setCowVertex(route->at(route->size() -1));
	}*/
	if (route != nullptr && !route->empty()) {
		double diffX = abs(this->getX() - route->at(0)->getX());
		double diffY = abs(this->getY() - route->at(0)->getY());

		double mag = sqrt(pow(diffX, 2) + pow(diffY, 2));

		if (this->getX() != route->at(0)->getX()) {
			if (this->getX() > route->at(0)->getX()) {
				this->setX(this->getX() - diffX / mag);
			} else {
				this->setX(this->getX() + diffX / mag);
			}
		}

		if (this->getY() != route->at(0)->getY()) {
			if (this->getY() > route->at(0)->getY()) {
				this->setY(this->getY() - diffY / mag);
			} else {
				this->setY(this->getY() + diffY / mag);
			}
		}


		if (this->getX() > route->at(0)->getX() - 2 && this->getX() < route->at(0)->getX() + 2 && this->getY() > route->at(0)->getY() - 2 && this->getY() < route->at(0)->getY() +2) {
			graph->setCowVertex(route->at(route->size() -1));
			route->erase(route->begin());
			route->shrink_to_fit();
		}
	}

}

void Cow::chase() {

	route = graph->getRouteToRabbit();
	graph->setCowVertex(route->at(route->size() -1));

}

void Cow::wander() {
	Vertex* wanderToVertex = nullptr;
	while(wanderToVertex == nullptr) {
		std::random_device dev;
		std::default_random_engine dre(dev());
		std::uniform_int_distribution<int> dist1(0, graph->getCowVertex()->getEdges()->size() - 1);

		int index = dist1(dre);
		wanderToVertex = graph->getCowVertex()->getEdges()->at(index)->getChild();
		std::cout << "in while" << std::endl;
	}
	route->push_back(wanderToVertex);
	graph->setCowVertex(wanderToVertex);
	//graph->setCowVertex(route->at(route->size() -1));
}

void Cow::update() {

	m_pStateMachine->Update();	
}


Cow::~Cow(void)
{
}
