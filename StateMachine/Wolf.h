#pragma once

#include "Agent.h"
#include "WolfStateMachine.h"
#include "SteeringBehaviors.h"
#include "Wander.h"

class WolfStateMachine;

static SMnamespace::Vector2 enclosureCenter(300.0f, 350);
static float radiusEnclosure = 100;
static float LimitDistanceWolf = 200;

class Wolf : public Agent
{
private:
	WolfStateMachine* m_pWolfStateMachine;
	SteeringBehaviors* m_pSteeringBehaviors;

	//SMnamespace::Vector2 m_wolfPos{ 50, 50 };
	
	

public:
	Wolf();
	~Wolf();

	virtual void Update() override;
	WolfStateMachine* getStateMachine() { return m_pWolfStateMachine; };
	SteeringBehaviors* getSteeringBehavior() { return m_pSteeringBehaviors; };

};


