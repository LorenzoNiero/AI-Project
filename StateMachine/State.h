#pragma once
#include <iostream>

template <class T>
class State {
public:
<<<<<<< HEAD
	virtual ~State() {};
=======
	virtual ~State(){};
>>>>>>> 75c8efe2055a02c38c37a49ddb2ad19269e72cbe
	virtual void Enter(T*) = 0;
	virtual void Execute(T*) = 0;
	virtual void Exit(T*) = 0;
};
	