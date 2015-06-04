#include "SteeringBehaviors.h"

void SteeringBehaviors::Calculate()
{
	m_steering.Zero();
	SumForces();
}

//sommare i comportamenti; evade, wander oppure seek, pursuit
void SteeringBehaviors::SumForces()
{
	Vector2 force = Vector2::ZERO;
	if (SeekIsOn()) 
		force += Seek(m_target);
	if (FleeIsOn()) 
		force += Flee(m_target);
	if (ArriveIsOn()) 
		force += Arrive(m_target);
	if (PursuitIsOn()) 
		force += Pursuit(m_evader);
	if (EvadeIsOn()) 
		force += Evade(m_evader);
	if (WanderIsOn()) 
		force += Wander();

	m_steering += force;
}


Vector2 SteeringBehaviors::Seek(const Vector2& target)
{
	Vector2 distance, desiredVelocity, force;
	distance = target - m_agent->getPosition();
	desiredVelocity = distance.NormalizeCopy() * m_agent->getMaxVelocity();
	force = desiredVelocity - m_agent->getVelocity();
	
	return force;
}

Vector2 SteeringBehaviors::Flee(const Vector2& target)
{
	Vector2 distance, desiredVelocity, force;
	distance = m_agent->getPosition() - target;
	desiredVelocity = distance.NormalizeCopy() * m_agent->getMaxVelocity();
	force = desiredVelocity - m_agent->getVelocity();

	return force;
}

Vector2 SteeringBehaviors::Arrive(const Vector2& target)
{
	Vector2 desiredVelocity, force;
	desiredVelocity = target - m_agent->getPosition();
	float d = desiredVelocity.Length();
	desiredVelocity.Normalize();

	if (d < 100) 
	{
		float m = d/100;
		desiredVelocity *= m;
	}
	else 
	{
		desiredVelocity *= m_agent->getMaxVelocity();
	}
	force = desiredVelocity - m_agent->getVelocity();
	
	return force;
}

Vector2 SteeringBehaviors::Pursuit(const Agent* target)
{
	Vector2 distance, targetFuturePosition;
	float T;

	//distance = target->getPosition() - m_agent->getPosition();
	distance = m_agent->getPosition();
	distance.Distance(target->getPosition());

	T = distance.Length() / target->getMaxVelocity();
	targetFuturePosition = target->getPosition() + target->getVelocity() * T;

	return Seek(targetFuturePosition);
}

Vector2 SteeringBehaviors::Evade(const Agent* target)
{
	Vector2 distance, targetFuturePosition;
	float T;

	//distance = target->getPosition() - m_agent->getPosition();
	distance = m_agent->getPosition();
	distance.Distance(target->getPosition());

	T = distance.Length() / target->getMaxVelocity();
	targetFuturePosition = target->getPosition() + target->getVelocity() * T;

	return Flee(targetFuturePosition);
}

Vector2 SteeringBehaviors::Wander()
{
	Vector2 circleCenter, desiredVelocity, wanderForce;
	Vector2 displacement = { 0, -1 };
	float wanderAngle = 0;

	circleCenter = m_agent->getVelocity();
	desiredVelocity = circleCenter.NormalizeCopy() * m_agent->getCircleDistance();

	desiredVelocity = displacement.NormalizeCopy() * m_agent->getCircleRadius();

	//set angle, randomly change the vector direction by making it change its current angle
	Vector2 pos;
	pos.x = cos(wanderAngle) * displacement.Length();
	pos.y = sin(wanderAngle) * displacement.Length();
	m_agent->setPosition(pos);
	
	wanderAngle += rand() * m_agent->getAngleChange() - m_agent->getAngleChange() * 0.5f;

	wanderForce = circleCenter + displacement;
	
	return wanderForce;
}

//TO DO: da non implementare
//obstacle
//Vector2 SteeringBehaviors::ObstacleAvoidance()
//{
//	return;
//}
//
//Vector2 SteeringBehaviors::WallAvoidance(const Vector2& target)
//{
//	return;
//}
//
//Vector2 SteeringBehaviors::Interpose(const Vector2& target)
//{
//	return;
//}
//
////group
//Vector2 SteeringBehaviors::Separation(const std::vector<Agent*>& neighbors)
//{
//	return;
//}
//
//Vector2 SteeringBehaviors::Cohesion(const std::vector<Agent*>& neighbors)
//{
//	return;
//}
//
//Vector2 SteeringBehaviors::Alignment(const Vector2& target)
//{
//	return;
//}