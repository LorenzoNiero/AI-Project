#pragma once
#include "Agent.h"

template <class T>
class StateMachine {

public:
<<<<<<< HEAD
	
	virtual ~StateMachine() {};
=======
	virtual ~StateMachine() {};
<<<<<<< HEAD
	virtual void SetCurrentState(State<Agent>* s) = 0;
	virtual State<Agent>* GetCurrentState() const = 0;
=======
>>>>>>> 6f75ee868abd8900275163ca0532d07609ab58e6
	virtual void SetCurrentState(State<T>* s) = 0;
	virtual State<T>* GetCurrentState() const = 0;
>>>>>>> 75c8efe2055a02c38c37a49ddb2ad19269e72cbe

	virtual void SetPreviousState(State<T>* s) = 0;
	virtual State<T>* GetPreviousState() const = 0;

	virtual void  Update() const = 0;

	virtual void  ChangeState(State<T>* pNewState) = 0;

	virtual void  RevertToPreviousState() = 0;

	virtual bool  isInState(const State<T>& st) const = 0;
};