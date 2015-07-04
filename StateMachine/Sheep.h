#pragma once
#include "Agent.h"
#include "SteeringBehaviors.h"
#include "SheepStateMachine.h"
#include "Pasture.h"


class SheepStateMachine;

class Sheep : public Agent
{
private:
	SheepStateMachine* m_pSheepStateMachine;
	SteeringBehaviors* m_pSteeringBehaviors;

	//	SMnamespace::Vector2 m_wolfPos{ 50, 50 };

public:
	Sheep();
	~Sheep();

	virtual void Update() override;
	SheepStateMachine* getStateMachine() { return m_pSheepStateMachine; };
	SteeringBehaviors* getSteeringBehavior() { return m_pSteeringBehaviors; };

};
