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
	
	Vector2 getAcceleration() const { return m_acceleration; }
	void setAcceleration(Vector2 val) { m_acceleration = val; }

private:
	Vector2 m_position;
	Vector2 m_velocity;
	Vector2 m_acceleration;
	float m_maxVelocity;
};