#pragma once
#include <iostream>
#include <vector>

class Edge;
class Vertex
{
public:
	Vertex(int x, int y);

	std::vector<Edge*>* getEdges();

	Vertex* addEdge(Vertex* child, int weight);
	void setEdgeWeight(Vertex* child, int weight);

	int getX();
	int getY();

	bool hasCow();
	bool hasRabbit();

	Vertex* moveCow();
	Vertex* moveRabbit();

	void setCow(bool cow);
	void setRabbit(bool rabbit);

	void setG(int g);
	void setH(int h);
	void setF(int f);

	int getG();
	int getH();
	int getF();


	~Vertex(void);
private:
	bool cow;
	bool rabbit;
	int x;
	int y;

	int g; // this node cost
	int h; // heuristic estimate to goal
	int f; // sum

	std::vector<Edge*>* edges;
	bool visited;

};

