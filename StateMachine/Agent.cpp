#include "Agent.h"

Vector2 Agent::getPosition() { return m_position; }
void Agent::setPosition(Vector2 val) { m_position = val; }

float Agent::getMaxVelocity()  { return m_maxVelocity; }
void Agent::setMaxVelocity(float val) { m_maxVelocity = val; }

Vector2 Agent::getVelocity()  { return velocity; }
void Agent::setVelocity(Vector2 val) { velocity = val; }