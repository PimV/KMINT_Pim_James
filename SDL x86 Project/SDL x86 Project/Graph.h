#pragma once
#include <iostream>
#include <vector>
class Vertex;
class Rabbit;
class Cow;
class Weapon;
class Graph
{
public:
	Graph(void);

	Vertex* createRoot(int x, int y);
	Vertex* createVertex(int x, int y);

	void insertLast(Vertex* v);
	void linkVertex(Vertex* source, Vertex* target, int weight);
	void removeVertex(Vertex* v);

	void setCowVertex(Vertex* v);
	void setRabbitVertex(Vertex* v);
	void setWeaponVertex(Vertex* v);

	void setCow(Cow* cow);
	Cow* getCow();

	void setRabbit(Rabbit* rabbit);
	Rabbit* getRabbit();

	void setWeapon(Weapon* weapon);
	Weapon* getWeapon();

	void teleportRabbit();

	Vertex* getCowVertex();
	Vertex* getRabbitVertex();
	int calculateHeuristic(Vertex* start, Vertex* goal);
	std::vector<Vertex*>* AStar(Vertex* start, Vertex* goal);

	std::vector<Vertex*>* getRouteToRabbit();

	std::vector<Vertex*>* getVertices();

	~Graph(void);

private:
	Vertex* root;
	Vertex* rabbitVertex;
	Vertex* cowVertex;
	Vertex* weaponVertex;
	Cow* cow;
	Rabbit* rabbit;
	Weapon* weapon;
	std::vector<Vertex*>* vertices;
};

