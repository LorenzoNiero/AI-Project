#pragma once
#include "State.h"

class Agent {
public:
	virtual ~Agent() {};
	virtual void Update() = 0;
};