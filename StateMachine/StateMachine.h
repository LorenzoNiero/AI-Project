#pragma once
#include "Agent.h"

template <class Agent>
class StateMachine {

public:
	virtual ~StateMachine() = 0;
	virtual void SetCurrentState(State<Agent>* s) = 0;
	virtual State<Agent>* GetCurrentState() const = 0;

	virtual void SetPreviousState(State<Agent>* s) = 0;
	virtual State<Agent>* GetPreviousState() const = 0;

	virtual void  Update() const = 0;

	virtual void  ChangeState(State<Agent>* pNewState) = 0;

	virtual void  RevertToPreviousState() = 0;

	virtual bool  isInState(const State<Agent>& st) const = 0;
};