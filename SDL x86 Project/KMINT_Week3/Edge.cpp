#include "Edge.h"
#include "Vertex.h"


Edge::Edge(void)
{
}


int Edge::getWeight() {
	return this->weight;
}

void Edge::setWeight(int weight) {
	this->weight = weight;
}

Vertex* Edge::getParent() {
	return this->parent;
}

void Edge::setParent(Vertex* parent) {
	this->parent = parent;
}

Vertex* Edge::getChild() {
	return this->child;
}

void Edge::setChild(Vertex* child) {
	this->child = child;
}

Edge::~Edge(void)
{
}
