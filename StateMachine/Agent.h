#pragma once
#include "State.h"
#include "Vector2.h"

class Agent {
public:
	virtual ~Agent() {};
	virtual void Update() = 0;
	
	Vector2 getPosition() const { return m_position; }
	void setPosition(Vector2 val) { m_position = val; }

	Vector2 Velocity() const { return m_velocity; }
	void Velocity(Vector2 val) { m_velocity = val; }

private :
	Vector2 m_position;
	Vector2 m_velocity;
};