#pragma once
#include "State.h"
#include "Vector2.h"

class Agent {
public:
	virtual ~Agent() {};
	virtual void Update() = 0;
	
	Vector2 getPosition() const { return m_position; }
	void setPosition(Vector2 val) { m_position = val; }

	float getMaxVelocity() const { return m_maxVelocity; }
	void setMaxVelocity(float val) { m_maxVelocity = val; }

	Vector2 getVelocity() const { return velocity; }
	void setVelocity(Vector2 val) { velocity = val; }

private :
	Vector2 m_position;
	Vector2 velocity;
	float m_maxVelocity;
};