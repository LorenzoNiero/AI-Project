#pragma once
#include "StateMachine.h"
#include "Wolf.h"

class Wolf;
class WolfStateMachine : StateMachine < Wolf >
{
private:
	State<Wolf>*   m_pCurrentState;
	State<Wolf>*   m_pPreviousState;
	Wolf* m_pCurrentAgent;

public:
	WolfStateMachine(Wolf* agent) :
		m_pCurrentState(nullptr),
		m_pPreviousState(nullptr),
		m_pCurrentAgent(agent)
	{};

	virtual ~WolfStateMachine() {};

	void SetCurrentState(State<Wolf>* s){ m_pCurrentState = s; }
	State<Wolf>*  GetCurrentState()  const{ return m_pCurrentState; }

	void SetPreviousState(State<Wolf>* s){ m_pPreviousState = s; }
	State<Wolf>*  GetPreviousState() const{ return m_pPreviousState; }

	virtual void  Update() const override;

	void  ChangeState(State<Wolf>* pNewState);

	void  RevertToPreviousState(){ ChangeState(m_pPreviousState); }

	bool  isInState(const State<Wolf>& st) const { return true; };

};



