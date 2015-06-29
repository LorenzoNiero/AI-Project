#include "Wolf.h"

Wolf::Wolf() {

	setPosition({ 20.0f, 50.0f });
	//setVelocity({ 0.5f, 0.5f }); // non dovrebbe avere una base di velocità, dovrebbe essere 0

	setAcceleration({ 0.5f, 0.5f });
	setMaxVelocity(2.0f);

	//m_pWolfStateMachine = new WolfStateMachine(this);
	/*State<Wolf>* m_pStartState = (State<Wolf>*)&Idle::getIInstance();
	m_pMinerStateMachine->SetCurrentState(m_pStartState);*/

	m_pSteeringBehaviors = new SteeringBehaviors(this);


}

void Wolf::Update()
{
	//m_pWolfStateMachine->Update();
	m_pSteeringBehaviors->Calculate();
	setVelocity(m_pSteeringBehaviors->GetForce());
	setPosition(getPosition() + getVelocity());
}

