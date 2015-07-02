#include "Wolf.h"

Wolf::Wolf() {

	setPosition({ 200.0f, 250.0f });
	setVelocity({ 0.5f, 0.5f }); // non dovrebbe avere una base di velocità, dovrebbe essere 0
	
	setAcceleration({ 0.5f, 0.5f });
	setMaxVelocity(2.0f);

	setCircleRadius(10);
	setCircleDistance(2);
	setAngleChange(30);

	m_pWolfStateMachine = new WolfStateMachine(this);
	State<Wolf>* m_pStartState = (State<Wolf>*)&Wander::getIInstance();
	m_pWolfStateMachine->SetCurrentState(m_pStartState);

	m_pSteeringBehaviors = new SteeringBehaviors(this);


	m_pWolfStateMachine->ChangeState(m_pStartState);
}

Wolf::~Wolf()
{
	/*if (m_pWolfStateMachine){
		delete m_pWolfStateMachine;
	}

	if (m_pSteeringBehaviors){
		delete m_pSteeringBehaviors;
	}*/
}

void Wolf::Update()
{
	//std::cout << "Update Cane " << std::endl;

	m_pWolfStateMachine->Update();
	m_pSteeringBehaviors->Calculate();
	setVelocity(m_pSteeringBehaviors->GetForce());
	setPosition(getPosition() + getVelocity());

	/*setVelocity( (getVelocity() + m_pSteeringBehaviors->GetForce()));
	m_vVelocity.Truncate(getMaxVelocity());
	setPosition(getPosition() + getVelocity());*/
}

