#include "Miner.h"

Miner::Miner() {

	

	m_istamina = 0;
	m_eLocation = home;

	std::cout << "creo minatore" << std::endl;

	setPosition({ 20, 50 });
	setVelocity({ 0.0001f, 0.0001f });
	setAcceleration({ 0.0001f, 0.0001f });
	setMaxVelocity(0.001f);

	m_pMinerStateMachine = new MinerStateMachine(this);
	State<Miner>* m_pStartState = (State<Miner>*)&Idle::getIInstance();
	m_pMinerStateMachine->SetCurrentState(m_pStartState);

	m_pSteeringBehaviors = new SteeringBehaviors(this);

		
}

void Miner::Update()
{
	m_pMinerStateMachine->Update();
	m_pSteeringBehaviors->Calculate();
	setVelocity(m_pSteeringBehaviors->GetForce());
	setPosition(getPosition()+getVelocity());
}
