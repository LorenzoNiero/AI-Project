#include "Pasture.h"


Pasture* Pasture::m_pIInstance = nullptr;

State<Sheep>& Pasture::getIInstance()
{
	static Pasture theInstance;
	m_pIInstance = &theInstance;
	return *m_pIInstance;
};

void Pasture::Enter(Sheep* wolf){
	std::cout << "Entering Pasture Sheep" << std::endl;
	wolf->getSteeringBehavior()->CohesionOn();
}

void Pasture::Execute(Sheep* wolf){

	/*float distance = wolf->getPosition().Distance(enclosureCenter);
	if (distance > LimitDistanceWolf || distance < radiusEnclosure){
		SMnamespace::Vector2 VecVel = wolf->getVelocity();
		VecVel.x *= -1;
		VecVel.y *= -1;
		wolf->setVelocity(VecVel);
	}
	std::cout << distance << "Update Cane execute " << std::endl;*/

}

void Pasture::Exit(Sheep* wolf){
	std::cout << "Exit Pasture Sheep" << std::endl;
	wolf->getSteeringBehavior()->CohesionOff();
}



