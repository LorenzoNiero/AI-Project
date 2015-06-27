#pragma once

#include "Agent.h"
#include "WolfStateMachine.h"
#include "SteeringBehaviors.h"

class Wolf : public Agent
{
public:
	Wolf();
	~Wolf(){
		delete m_pWolfStateMachine;
		delete m_pSteeringBehaviors;
	};

	void Update();
	WolfStateMachine* getStateMachine() { return m_pWolfStateMachine; };
	SteeringBehaviors* getSteeringBehavior() { return m_pSteeringBehaviors; };
	
private:
	WolfStateMachine* m_pWolfStateMachine;
	SteeringBehaviors* m_pSteeringBehaviors;
	
	SMnamespace::Vector2 m_minerPos{ 50, 50 };
	SMnamespace::Vector2 m_minerVel{ 1, 1 };
	SMnamespace::Vector2 m_minerAcc{ 1, 1 };


};


