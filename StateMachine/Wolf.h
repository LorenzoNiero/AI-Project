#pragma once

#include "Agent.h"
#include "WolfStateMachine.h"
#include "SteeringBehaviors.h"

class WolfStateMachine;

class Wolf : public Agent
{
public:
	Wolf();
	~Wolf(){
		if (m_pWolfStateMachine)
			delete m_pWolfStateMachine;

		if (m_pSteeringBehaviors)
			delete m_pSteeringBehaviors;
	};

	virtual void Update() override;
	WolfStateMachine* getStateMachine() { return m_pWolfStateMachine; };
	SteeringBehaviors* getSteeringBehavior() { return m_pSteeringBehaviors; };

private:
	WolfStateMachine* m_pWolfStateMachine;
	SteeringBehaviors* m_pSteeringBehaviors;

	SMnamespace::Vector2 m_minerPos{ 50, 50 };
	SMnamespace::Vector2 m_minerVel{ 1, 1 };
	SMnamespace::Vector2 m_minerAcc{ 1, 1 };


};


