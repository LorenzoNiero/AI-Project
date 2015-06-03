#pragma once
#include "State.h"
#include "Vector2.h"

class Agent {
public:
	virtual ~Agent() {};
	virtual void Update(){};
	
	virtual void setPosition(Vector2 val);
	virtual Vector2 getPosition();

	float getMaxVelocity();
	void setMaxVelocity(float val);

	Vector2 getVelocity();
	void setVelocity(Vector2 val);

private:
	Vector2 m_position;
	Vector2 velocity;
	float m_maxVelocity;
};