#pragma once
#include <iostream>

template <class T>
class State {
public:
<<<<<<< HEAD

=======
>>>>>>> 34b5da8bd0078a1ae9177fcc195eb654d645f196
	virtual ~State(){};
	virtual void Enter(T*) = 0;
	virtual void Execute(T*) = 0;
	virtual void Exit(T*) = 0;
};
	