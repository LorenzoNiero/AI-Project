#include "Miner.h"

Miner::Miner() {

	std::cout << "creo minatore" << std::endl;

	m_istamina = 0;
	m_eLocation = home;

	setPosition({ 20, 50 });
	setVelocity({ 1, 2 });
	setAcceleration({ 2, 1 });
	setMaxVelocity(1.0f);

	m_pMinerStateMachine = new MinerStateMachine(this);
	State<Miner>* m_pStartState = (State<Miner>*)&Idle::getIInstance();
	m_pMinerStateMachine->SetCurrentState(m_pStartState);

	m_pSteeringBehaviors = new SteeringBehaviors(this);
}

void Miner::Update()
{
	m_pMinerStateMachine->Update();
	m_pSteeringBehaviors->Calculate();
}
