#pragma once
#include "State.h"
#include "Vector2.h"

class Agent {
public:
	virtual ~Agent() {};
	virtual void Update() = 0;
	
	Vector2 getPosition() const { return m_vPosition; }
	void setPosition(Vector2 val) { m_vPosition = val; }

	float getMaxVelocity() const { return m_fMaxVelocity; }
	void setMaxVelocity(float val) { m_fMaxVelocity = val; }

	Vector2 getVelocity() const { return m_vVelocity; }
	void setVelocity(Vector2 val) { m_vVelocity = val; }

	float getCircleDistance() const { return m_fCircleDistance; }
	void setCircleDistance(float val) { m_fCircleDistance = val; }

	float getCircleRadius() const { return m_fCircleRadius; }
	void setCircleRadius(float val) { m_fCircleRadius = val; }

	float getAngleChange() const { return m_fAngleChange; }
	void setAngleChange(float val) { m_fAngleChange = val; }

private :
	Vector2 m_vPosition;
	Vector2 m_vVelocity;
	float m_fCircleDistance;
	float m_fCircleRadius;
	float m_fAngleChange;
	float m_fMaxVelocity;
};