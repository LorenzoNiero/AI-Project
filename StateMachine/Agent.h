#pragma once
#include "State.h"

class Agent {
public:
	virtual ~Agent() = 0;
	virtual void Update() = 0;
};