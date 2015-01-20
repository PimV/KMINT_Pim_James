#include "Cow.h"
#include "GameStateManager.h"
#include "CowOwnedStates.h"
#include <random>


Cow::Cow(Vector2D position,
		 Vector2D velocity,
		 double    max_speed,
		 double    mass,
		 double    turn_rate,
		 double    max_force) : MovingEntity(position, velocity, max_speed, mass, turn_rate, max_force) 
{
	this->setTexture(IMG_LoadTexture(GameStateManager::Instance()->getMySDL()->getRenderer(), "cow-2.png"));

	m_pStateMachine = new StateMachine<Cow>(this);
	m_pStateMachine->SetCurrentState(WanderAroundCow::Instance());
	m_pStateMachine->CurrentState()->Enter(this);

	m_pSteering = new SteeringBehaviors();
	m_pSteering->setOrigin(this);
}



void Cow::draw() {
	SDL_Rect rect;
	rect.x = static_cast<int>(this->m_vPosition.x);
	rect.y = static_cast<int>(this->m_vPosition.y);
	rect.w = 30;
	rect.h = 30;
	GameStateManager::Instance()->getMySDL()->drawTexture(this->getTexture(), &rect, NULL);
	GameStateManager::Instance()->getMySDL()->drawText(this->GetFSM()->GetNameOfCurrentState(), this->m_vPosition.x - 15, this->m_vPosition.y - 30, 100, 16);
}

SteeringBehaviors* Cow::getSteeringMechanism() {
	return m_pSteering;
}

void Cow::update(double dt) {
	Vector2D steer = m_pSteering->calculate();

	Vector2D acc = steer / m_dMass;


	m_vVelocity += acc * dt;

	m_vVelocity.Truncate(m_dMaxSpeed);

	//Flip coordinates when nearing edges
	Vector2D newPos = m_vPosition + (m_vVelocity * dt);

	if (newPos.x + 30 > 1280 || newPos.x - 30 < 0) {
		m_vVelocity.x = -m_vVelocity.x;
	}

	if (newPos.y + 30 > 720 || newPos.y - 30 < 0) {
		m_vVelocity.y = -m_vVelocity.y;
	}

	m_vPosition += m_vVelocity * dt;

	if (m_vVelocity.LengthSq() > 0.00000001)
	{
		m_vHeading = Vec2DNormalize(m_vVelocity);
		m_vSide = m_vHeading.Perp();
	}

	//m_pStateMachine->Update();	
}


Cow::~Cow(void)
{
}
