#include "SteeringBehaviors.h"

void SteeringBehaviors::Calculate()
{
	m_steering.ZERO;
	SumForces();
	//m_steering += m_agent->getVelocity();
	m_steering.Truncate(m_agent->getMaxVelocity());
	
	//std::cout << "    STEERING   :  " << m_steering.x << " , " << m_steering.y << std::endl;
}

//sommare i comportamenti; evade, wander oppure seek, pursuit
void SteeringBehaviors::SumForces()
{

	SMnamespace::Vector2 force = SMnamespace::Vector2::ZERO;
	if (SeekIsOn()) 
		m_steering += Seek(m_target);
	if (FleeIsOn()) 
		m_steering += Flee(m_target);
	if (ArriveIsOn()) 
		m_steering += Arrive(m_target);
	if (PursuitIsOn()) 
		m_steering += Pursuit(m_evader);
	if (EvadeIsOn()) 
		m_steering += Evade(m_evader);
	if (WanderIsOn()) 
		m_steering += Wander();
}


SMnamespace::Vector2 SteeringBehaviors::Seek(const SMnamespace::Vector2& target)
{
	SMnamespace::Vector2 desiredVelocity, force;
	float stopRadius = 0.1f;
	desiredVelocity = target - m_agent->getPosition();
	if (desiredVelocity.Length() < stopRadius){ return SMnamespace::Vector2::ZERO; }
	desiredVelocity = desiredVelocity.NormalizeCopy();
	desiredVelocity *= m_agent->getMaxVelocity();
	force = desiredVelocity - m_agent->getVelocity();

	return force;
}

SMnamespace::Vector2 SteeringBehaviors::Flee(const SMnamespace::Vector2& target)
{
	SMnamespace::Vector2 distance, desiredVelocity, force;
	distance = m_agent->getPosition() - target;
	desiredVelocity = distance.NormalizeCopy() * m_agent->getMaxVelocity();
	force = desiredVelocity - m_agent->getVelocity();

	return force;
}

SMnamespace::Vector2 SteeringBehaviors::Arrive(const SMnamespace::Vector2& target)
{
	SMnamespace::Vector2 desiredVelocity, force;
	float slowRadius = 100.0f;
	float stopRadius = 0.1f;
	desiredVelocity = target - m_agent->getPosition();
	float distance = desiredVelocity.Length(); 
	//std::cout << " DISTANZA : " << distance << std::endl;
	desiredVelocity=desiredVelocity.NormalizeCopy();

	if (distance < slowRadius)
	{
		if (distance < stopRadius) { return SMnamespace::Vector2::ZERO; }
		float m = (distance / slowRadius) ;
		//std::cout << " DISTANZA M : " << m << std::endl;
		desiredVelocity *= m;
	}
	else 
	{
		desiredVelocity *= m_agent->getMaxVelocity();
	}
	force = desiredVelocity - m_agent->getVelocity();
	
	return force;
}

SMnamespace::Vector2 SteeringBehaviors::Pursuit(const Agent* target)
{
	SMnamespace::Vector2 distance, targetFuturePosition;
	float T;

	//distance = target->getPosition() - m_agent->getPosition();
	distance = m_agent->getPosition();
	distance.Distance(target->getPosition());

	T = distance.Length() / target->getMaxVelocity();
	targetFuturePosition = target->getPosition() + target->getVelocity() * T;

	return Seek(targetFuturePosition);
}

SMnamespace::Vector2 SteeringBehaviors::Evade(const Agent* target)
{
	SMnamespace::Vector2 distance, targetFuturePosition;
	float T;

	//distance = target->getPosition() - m_agent->getPosition();
	distance = m_agent->getPosition();
	distance.Distance(target->getPosition());

	T = distance.Length() / target->getMaxVelocity();
	targetFuturePosition = target->getPosition() + target->getVelocity() * T;

	return Flee(targetFuturePosition);
}

SMnamespace::Vector2 SteeringBehaviors::Wander()
{
	static float wanderAngle = 0;
	// Calculate the circle center
	SMnamespace::Vector2 circleCenter, wanderForce;
	circleCenter = m_agent->getVelocity();
	circleCenter.Normalize();
	
	//circleCenter.scaleBy(CIRCLE_DISTANCE);
	//
	// Calculate the displacement force
	SMnamespace::Vector2 displacement = { 0, -1 };
	//displacement = new Vector3D(0, -1);
	//displacement.scaleBy(CIRCLE_RADIUS);
	//
	// Randomly change the vector direction
	// by making it change its current angle
	setAngle(displacement, wanderAngle);
	//
	// Change wanderAngle just a bit, so it
	// won't have the same value in the
	// next game frame.
	wanderAngle += rand() * m_agent->getAngleChange() - m_agent->getAngleChange() * 0.5f;
	std::cout << "" << wanderAngle << std::endl;
	//
	// Finally calculate and return the wander force
	/*var wanderForce : Vector3D;
	wanderForce = circleCenter.add(displacement);
	return wanderForce;*/
	wanderForce = circleCenter + displacement;

	return wanderForce;
	
	
	//SMnamespace::Vector2 circleCenter, desiredVelocity, wanderForce;
	//SMnamespace::Vector2 displacement = { 0, -1 };
	//static float wanderAngle =0;

	//circleCenter = m_agent->getVelocity();
	//
	//desiredVelocity = circleCenter.NormalizeCopy() *m_agent->getCircleDistance();
	//
	//desiredVelocity = displacement.NormalizeCopy() * m_agent->getCircleRadius();
	//std::cout << "" << desiredVelocity.x << "  " << desiredVelocity.y << std::endl;
	////set angle, randomly change the vector direction by making it change its current angle
	////SMnamespace::Vector2 pos = displacement;
	////pos.x = cos(wanderAngle) * displacement.Length();
	////pos.y = sin(wanderAngle) * displacement.Length();
	//////m_agent->setPosition(pos);
	////displacement = pos;
	//setAngle(displacement, wanderAngle);
	//
	//wanderAngle += rand() * m_agent->getAngleChange() - m_agent->getAngleChange() * 0.5f;

	//wanderForce = circleCenter + displacement;
	//
	//return wanderForce;
}

void SteeringBehaviors::setAngle(SMnamespace::Vector2 &vect, float angle){
	SMnamespace::Vector2 pos;
	pos.x = cos(angle) * vect.Length();
	pos.y = sin(angle) * vect.Length();
	vect = pos;
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

//group
SMnamespace::Vector2 SteeringBehaviors::Separation(const std::vector<Agent*>& neighbors)
{
	return SMnamespace::Vector2::ZERO;
}

SMnamespace::Vector2 SteeringBehaviors::Cohesion(const std::vector<Agent*>& neighbors)
{
	return SMnamespace::Vector2::ZERO;
}

SMnamespace::Vector2 SteeringBehaviors::Alignment(const SMnamespace::Vector2& target)
{
	return SMnamespace::Vector2::ZERO;
}