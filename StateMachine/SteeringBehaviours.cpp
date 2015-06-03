#include "SteeringBehaviors.h"

void SteeringBehaviors::Calculate()
{
}

//sommare i comportamenti; evade, wander oppure seek, pursuit
void SteeringBehaviors::SumForces()
{

	m_agent->setVelocity((m_agent->getVelocity() + desiredVelocity));
	m_agent->getVelocity().Truncate(m_agent->getMaxVelocity());

	m_agent->setPosition(m_agent->getPosition() + m_agent->getVelocity());
}


Vector2 SteeringBehaviors::Seek(const Vector2& target)
{
	m_target = target;

	Vector2 distance, desiredVelocity, force;
	distance = target - m_agent->getPosition();
	desiredVelocity = distance.NormalizeCopy() * m_agent->getMaxVelocity();
	force = desiredVelocity - m_agent->getVelocity();

	return force;
}

Vector2 SteeringBehaviors::Flee(const Vector2& target)
{
	m_target = target;

	Vector2 distance, desiredVelocity, force;
	distance = m_agent->getPosition() - target;
	desiredVelocity = distance.NormalizeCopy() * m_agent->getMaxVelocity();
	force = desiredVelocity - m_agent->getVelocity();

	return force;
}

Vector2 SteeringBehaviors::Arrive(const Vector2& target)
{

}

Vector2 SteeringBehaviors::Pursuit(const Agent* target)
{
}

Vector2 SteeringBehaviors::Evade(const Agent* target)
{
}

Vector2 SteeringBehaviors::Wander()
{
}

//TO DO: da non implementare
//obstacle
Vector2 SteeringBehaviors::ObstacleAvoidance()
{
}

Vector2 SteeringBehaviors::WallAvoidance(const Vector2& target)
{
}

Vector2 SteeringBehaviors::Interpose(const Vector2& target)
{
}

//group
Vector2 SteeringBehaviors::Separation(const std::vector<Agent*>& neighbors)
{
}

Vector2 SteeringBehaviors::Cohesion(const std::vector<Agent*>& neighbors)
{
}

Vector2 SteeringBehaviors::Alignment(const Vector2& target)
{
}