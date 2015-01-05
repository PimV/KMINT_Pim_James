#pragma once
#include "Entity.h"
#include <vector>
#include "StateMachine.h"

class Vertex;
class Weapon;
class Rabbit :
	public Entity
{
public:
	Rabbit(void);

	void draw();
	void update();

	void setRoute(std::vector<Vertex*>* route);
	std::vector<Vertex*>* getRoute();

	void wander();
	void flee();

	bool cowNearby();
	bool weaponNearby();
	bool pillNearby();

	void shootCow();
	void findWeapon();
	void grabWeapon();

	bool hasWeapon();
	void setWeapon(Weapon* weapon);

	bool onCow();
	bool onWeapon();

	void followRoute();

	void setDestination(Vertex* destination);

	StateMachine<Rabbit>* GetFSM() const { 
		return m_pStateMachine;
	};

	virtual ~Rabbit(void);

private:
	Vertex* destination;
	std::vector<Vertex*>* route;
	StateMachine<Rabbit>* m_pStateMachine;
	Weapon* weapon;
};