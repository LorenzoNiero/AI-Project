#include "Wander.h"


Wander* Wander::m_pIInstance = nullptr;

State<Wolf>& Wander::getIInstance()
{
	static Wander theInstance;
	m_pIInstance = &theInstance;
	return *m_pIInstance;
};

void Wander::Enter(Wolf* wolf){
	std::cout << "Entering Wander Wolf" << std::endl;
	wolf->getSteeringBehavior()->WanderOn();
}

void Wander::Execute(Wolf* wolf){
	
	float distance = wolf->getPosition().Distance( enclosureCenter);
	if (distance > LimitDistanceWolf || distance < radiusEnclosure){
		SMnamespace::Vector2 VecVel = wolf->getVelocity();
		VecVel.x *= -1;
		VecVel.y *= -1;
		wolf->setVelocity(VecVel);
	}
	//std::cout << distance << "Update Dog execute "  << std::endl;

}

void Wander::Exit(Wolf* wolf){
	std::cout << "Exit Wander Wolf" << std::endl;
	wolf->getSteeringBehavior()->WanderOff();

}

