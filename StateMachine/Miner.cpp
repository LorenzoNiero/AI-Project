#include "Miner.h"

Miner::Miner() {
	m_istamina = 0;
	m_eLocation = home;
	m_pMinerStateMachine = new MinerStateMachine(this);
	State<Miner>* m_pStartState = (State<Miner>*)&Idle::getIInstance();
	m_pMinerStateMachine->SetCurrentState(m_pStartState);
}

void Miner::Update()
{
	m_pMinerStateMachine->Update();
}
