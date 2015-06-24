#pragma once
#include "Agent.h"
class Sheep : public Agent
{
public:
	Sheep();
	~Sheep();

	virtual void Update() override;

};

