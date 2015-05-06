#pragma once
#include "Agent.h"

template <class T>
class StateMachine {

public:
<<<<<<< HEAD
=======
	virtual ~StateMachine() {};
	virtual void SetCurrentState(State<Agent>* s) = 0;
	virtual State<Agent>* GetCurrentState() const = 0;
>>>>>>> 34b5da8bd0078a1ae9177fcc195eb654d645f196

	virtual ~StateMachine() {};
	virtual void SetCurrentState(State<T>* s) = 0;
	virtual State<T>* GetCurrentState() const = 0;

	virtual void SetPreviousState(State<T>* s) = 0;
	virtual State<T>* GetPreviousState() const = 0;

	virtual void  Update() const = 0;

	virtual void  ChangeState(State<T>* pNewState) = 0;

	virtual void  RevertToPreviousState() = 0;

	virtual bool  isInState(const State<T>& st) const = 0;
};