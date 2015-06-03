#include "SteeringBehaviors.h"

void SteeringBehaviors::Calculate()
{
}

//sommare i comportamenti; evade, wander oppure seek, pursuit
void SteeringBehaviors::SumForces()
{
}

Vector2 SteeringBehaviors::Seek(const Vector2& target)
{
	int d = target - m_agent->
}

Vector2 SteeringBehaviors::Flee(const Vector2& target)
{
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