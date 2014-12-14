#pragma once
class Vertex;
class Edge
{
public:
	Edge(void);

	int getWeight();
	void setWeight(int weight);

	Vertex* getParent();
	void setParent(Vertex* parent);

	Vertex* getChild();
	void setChild(Vertex* child);

	~Edge(void);

private:
	int weight;
	Vertex* parent;
	Vertex* child;
};

