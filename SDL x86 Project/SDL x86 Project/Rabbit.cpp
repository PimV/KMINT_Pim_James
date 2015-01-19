#include "Rabbit.h"
#include "GameStateManager.h"
#include "Vertex.h"
#include "Graph.h"
#include "RabbitOwnedStates.h"
#include <random> 
#include "Edge.h"
#include "Cow.h"
Rabbit::Rabbit(void)
{
	this->setTexture(IMG_LoadTexture(GameStateManager::Instance()->getMySDL()->getRenderer(), "rabbit-3.png"));

	this->route = new std::vector<Vertex*>();

	m_pStateMachine = new StateMachine<Rabbit>(this);
	m_pStateMachine->SetCurrentState(WanderAroundRabbit::Instance());
	m_pStateMachine->CurrentState()->Enter(this);
}

void Rabbit::draw() {
	SDL_Rect rect;
	rect.x = this->getX();
	rect.y = this->getY();
	rect.w = 30;
	rect.h = 30;
	GameStateManager::Instance()->getMySDL()->drawTexture(this->getTexture(), &rect, NULL);
	GameStateManager::Instance()->getMySDL()->drawText(this->GetFSM()->GetNameOfCurrentState(), this->getX() - 25, this->getY() - 30, 100, 16);
}

void Rabbit::setDestination(Vertex* destination) {
	if (destination != nullptr) {
		this->setX(destination->getX());
		this->setY(destination->getY());
	}
}

void Rabbit::setRoute(std::vector<Vertex*>* route) {
	this->route = route;
}

std::vector<Vertex*>* Rabbit::getRoute() {
	return this->route;
}

void Rabbit::wander() {
	Vertex* newRabbitVertex = nullptr;
	while(newRabbitVertex == nullptr || newRabbitVertex == graph->getCowVertex() || newRabbitVertex == graph->getRabbitVertex()) {
		std::random_device dev;
		std::default_random_engine dre(dev());
		std::uniform_int_distribution<int> dist1(0, graph->getVertices()->size() - 1);

		int index = dist1(dre);
		newRabbitVertex = graph->getVertices()->at(index);
	}
	//this->setDestination(newRabbitVertex);
	this->route = this->getGraph()->AStar(this->getGraph()->getRabbitVertex(), newRabbitVertex);
	//this->getGraph()->setRabbitVertex(newRabbitVertex);

}

void Rabbit::flee() {
	std::vector<Vertex*>* fastestRoute = this->getGraph()->AStar(this->getGraph()->getRabbitVertex(), this->getGraph()->getCowVertex());
	for(size_t i = 0; i < this->getGraph()->getRabbitVertex()->getEdges()->size(); i++) {
		if (this->getGraph()->getRabbitVertex()->getEdges()->at(i)->getChild() != fastestRoute->at(0)) {
			this->route = this->getGraph()->AStar(this->getGraph()->getRabbitVertex(), this->getGraph()->getRabbitVertex()->getEdges()->at(i)->getChild());

			break;
		}
	}
}

bool Rabbit::cowNearby() {
	if (onCow()) {
		return true;
	}
	for(size_t i = 0; i < this->getGraph()->getRabbitVertex()->getEdges()->size(); i++) {
		if (this->getGraph()->getRabbitVertex()->getEdges()->at(i)->getChild() == this->getGraph()->getCowVertex()) {
			return true;		
		}
	}

	return false;
}


bool Rabbit::onCow() {
	if (this->getGraph()->getCowVertex() == this->getGraph()->getRabbitVertex()) {
		return true;
	}

	return false;
}

void Rabbit::followRoute() {
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
			//this->getGraph()->setRabbitVertex(route->at(route->size() -1));
			this->getGraph()->setRabbitVertex(route->at(0));
			route->erase(route->begin());
			route->shrink_to_fit();
		}
	}
}

void Rabbit::update() {
	this->m_pStateMachine->Update();
}


Rabbit::~Rabbit(void)
{
}
