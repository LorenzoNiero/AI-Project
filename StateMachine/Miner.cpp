#include "Miner.h"

Miner::Miner() {

	std::cout << "creo minatore" << std::endl;

	m_istamina = 0;
	m_eLocation = home;
	setAcceleration(m_minerAcc);
	//setPosition(m_minerPos);
	setVelocity(m_minerVel);


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
