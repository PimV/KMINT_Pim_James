#include "Vertex.h"
#include "Edge.h"
#include <random>

Vertex::Vertex(int x, int y)
{
	this->x = x;
	this->y = y;
	this->visited = false;
	this->edges = new std::vector<Edge*>();
	this->cow = false;
	this->rabbit = false;
}

bool Vertex::hasCow() {
	return this->cow;
}

bool Vertex::hasRabbit() {
	return this->rabbit;
}

void Vertex::setG(int g) {
	this->g = g;
}

void Vertex::setH(int h ) {
	this->h = h;
}

void Vertex::setF(int f) {
	this->f = f;
}

int Vertex::getG() {
	return this->g;
}

int Vertex::getH() {
	return this->h;
}
int Vertex::getF() {
	return this->f;
}
Vertex* Vertex::moveCow() {
	if (this->cow == true) {
		std::random_device dev;
		std::default_random_engine dre(dev());

		// random amount
		std::uniform_int_distribution<int> dist1(0, this->getEdges()->size() - 1);
		int index = dist1(dre);
		this->getEdges()->at(index)->getChild();

		Vertex* child = this->getEdges()->at(index)->getChild();
		Vertex* parent = this->getEdges()->at(index)->getParent();


		if (!child->hasRabbit()) {
			child->setCow(true);
			this->setCow(false);
			return child;
		}
	} 
	return this;
}

Vertex* Vertex::moveRabbit() {
	if (this->rabbit == true) {
		std::random_device dev;
		std::default_random_engine dre(dev());

		// random amount
		std::uniform_int_distribution<int> dist1(0, this->getEdges()->size() - 1);
		int index = dist1(dre);
		this->getEdges()->at(index)->getChild();

		Vertex* child = this->getEdges()->at(index)->getChild();
		Vertex* parent = this->getEdges()->at(index)->getParent();


		if (!child->hasCow()) {
			child->setRabbit(true);
			this->setRabbit(false);
			return child;
		}
	} 
	return this;
}

void Vertex::setCow(bool cow) {
	this->cow = cow;
}

void Vertex::setRabbit(bool rabbit) {
	this->rabbit = rabbit;
}

std::vector<Edge*>* Vertex::getEdges() {
	return this->edges;
}

Vertex* Vertex::addEdge(Vertex* child, int weight) {




	//child->addEdge(this, weight);
	if(this->getEdges()->size() == 0) {
		Edge* newEdge = new Edge();

		newEdge->setParent(this);
		newEdge->setChild(child);
		newEdge->setWeight(weight);
		this->edges->push_back(newEdge);
	} else {
		for (size_t j = 0; j < this->getEdges()->size(); j++) {
			if (this->getEdges()->at(j)->getParent() == this && this->getEdges()->at(j)->getChild() == child && this->getEdges()->at(j)->getWeight() == weight) {
				//std::cout << "Exact same edge exists" << std::endl;
			} else {
				Edge* newEdge = new Edge();

				newEdge->setParent(this);
				newEdge->setChild(child);
				newEdge->setWeight(weight);
				this->edges->push_back(newEdge);
			}
		}
	}

	if (child->getEdges()->size() == 0) {
		Edge* newEdge2 = new Edge();

		newEdge2->setParent(child);
		newEdge2->setChild(this);
		newEdge2->setWeight(weight);
		child->edges->push_back(newEdge2);
	} else {
		for (size_t j = 0; j < child->getEdges()->size(); j++) {
			if (child->getEdges()->at(j)->getParent() == child && child->getEdges()->at(j)->getChild() == this && child->getEdges()->at(j)->getWeight() == weight) {
				std::cout << "Exact same edge exists" << std::endl;
			} else {
				Edge* newEdge2 = new Edge();

				newEdge2->setParent(child);
				newEdge2->setChild(this);
				newEdge2->setWeight(weight);
				child->edges->push_back(newEdge2);
			}
		}
	}

	//this->edges->push_back(newEdge);
	//child->getEdges()->push_back(newEdge2);

	//bool exists = false;
	//for (size_t j = 0; j < this->getEdges()->size(); j++) {
	//	if (this->getEdges()->at(j)->getParent() == child && this->getEdges()->at(j)->getChild() == this) {
	//		exists = true;
	//		std::cout << "Exists" << std::endl;
	//		break;
	//	}
	//}

	//if (!exists) {
	//	std::cout << child->getX() <<std::endl;
	//	//child->addEdge(this, weight);

	//}



	return this;
}

void Vertex::setEdgeWeight(Vertex* child, int weight) {
	for(Edge* e : *this->edges) {
		if (e->getChild() == child) {
			e->setWeight(weight);
			for(Edge* e2 : *e->getChild()->getEdges()) {
				if (e2->getChild() == this) {
					e2->setWeight(weight);
				}
			}
		}
	}
}

int Vertex::getX() {
	return this->x;
}

int Vertex::getY() {
	return this->y;
}


Vertex::~Vertex(void)
{
}
