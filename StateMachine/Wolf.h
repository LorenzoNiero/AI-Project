#pragma once

#include "Agent.h"
#include "WolfStateMachine.h"
#include "SteeringBehaviors.h"
#include "Wander.h"

class WolfStateMachine;

class Wolf : public Agent
{
private:
	WolfStateMachine* m_pWolfStateMachine;
	SteeringBehaviors* m_pSteeringBehaviors;

	SMnamespace::Vector2 m_wolfPos{ 50, 50 };
	SMnamespace::Vector2 m_wolfVel{ 1, -1 };


public:
	Wolf();
	~Wolf();

	virtual void Update() override;
	WolfStateMachine* getStateMachine() { return m_pWolfStateMachine; };
	SteeringBehaviors* getSteeringBehavior() { return m_pSteeringBehaviors; };




};


