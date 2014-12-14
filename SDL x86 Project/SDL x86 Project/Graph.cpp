#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include <queue>
#include <math.h>
#include <algorithm>
#include <map>

Graph::Graph(void)
{
	this->vertices = new std::vector<Vertex*>();
	rabbitVertex = nullptr;
	cowVertex = nullptr;
}

Vertex* Graph::createRoot(int x, int y) {
	this->root = this->createVertex(x,y);
	return this->root;
}

Vertex* Graph::createVertex(int x, int y) {
	Vertex* v = new Vertex(x,y);
	return v;
}

void Graph::insertLast(Vertex* v) {
	if (this->vertices->size() == 0) {
		this->root = v;
	}
	this->vertices->push_back(v);
}

void Graph::linkVertex(Vertex* source, Vertex* target, int weight) {
	source->addEdge(target, weight);
}

void Graph::removeVertex(Vertex* v) {
	if (v == nullptr) {
		return;
	}

	for (size_t i = 0; i < v->getEdges()->size(); i++) {
		Edge* e = v->getEdges()->at(i);
		for (size_t j = 0; j < e->getChild()->getEdges()->size(); j++) {
			if (e->getChild()->getEdges()->at(j)->getChild() == v) {
				//delete e->getChild()->getEdges()->at(j);
			}
		}
	}
}

int Graph::calculateHeuristic(Vertex* start, Vertex* goal) {
	return sqrt(pow((start->getX() - goal->getX()), 2) + pow(start->getY() - goal->getY(), 2));
}

std::vector<Vertex*>* Graph::AStar(Vertex* start, Vertex* goal) {
	std::map<Vertex*, double> openList;
	std::vector<Vertex*>* closedList = new std::vector<Vertex*>();


	openList[start] = 0.0;

	Vertex* current = start; 
	closedList->push_back(current);

	double weightTillNow = 0;

	while(current != goal) {


		for(Edge* e : *current->getEdges()) {
			if (std::find(closedList->begin(), closedList->end(), e->getChild()) == closedList->end()) {
				int g = weightTillNow + e->getWeight();
				int h = calculateHeuristic(goal, e->getChild());
				int f = g + h;

				openList[e->getChild()] = f;
			}
		}

		//Shortest
		Vertex* shortestNode = nullptr;
		for(std::pair<Vertex*, double> mapPair : openList) {
			if (shortestNode == nullptr || mapPair.second < openList[shortestNode]) {
				shortestNode = mapPair.first;

			}
		}

		for(size_t i = 0; i < current->getEdges()->size(); i++) {
			if (current->getEdges()->at(i)->getChild() == shortestNode) {
				weightTillNow += current->getEdges()->at(i)->getWeight();
				break;
			}
		}
		current = shortestNode;

		closedList->push_back(current);

		//Clear openList
		openList = std::map<Vertex*, double>();
	}
	std::cout << "cl length:  " << closedList->size() << std::endl;
	return closedList;
}

void Graph::setCowVertex(Vertex* v) {
	this->cowVertex = v;
}

void Graph::setRabbitVertex(Vertex* v) {
	this->rabbitVertex = v;
}

Vertex* Graph::getCowVertex() {
	return this->cowVertex;
}

Vertex* Graph::getRabbitVertex() {
	return this->rabbitVertex;
}

std::vector<Vertex*>* Graph::getVertices() {
	return this->vertices;
}

Graph::~Graph(void)
{
}
