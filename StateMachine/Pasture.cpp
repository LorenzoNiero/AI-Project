#include "Pasture.h"


Pasture* Pasture::m_pIInstance = nullptr;

State<Sheep>& Pasture::getIInstance()
{
	static Pasture theInstance;
	m_pIInstance = &theInstance;
	return *m_pIInstance;
};

void Pasture::Enter(Sheep* sheep){
	std::cout << "Entering Pasture Sheep" << std::endl;
	
	if (sheep->isHead() == false){
		sheep->getSteeringBehavior()->AlignmentOn();
		sheep->getSteeringBehavior()->CohesionOn();
		sheep->getSteeringBehavior()->SeparationOn();
	}
}

void Pasture::Execute(Sheep* sheep){

	float distance = sheep->getPosition().Distance(enclosureCenter);
	if (distance > LimitDistanceWolf || distance < radiusEnclosure){
		SMnamespace::Vector2 VecVel = sheep->getVelocity();
		VecVel.x *= -1;
		VecVel.y *= -1;
		sheep->setVelocity(VecVel);
	}
	//std::cout << distance << "Update Cane execute " << std::endl;

}

void Pasture::Exit(Sheep* sheep){
	std::cout << "Exit Pasture Sheep" << std::endl;
	sheep->getSteeringBehavior()->AlignmentOff();
	sheep->getSteeringBehavior()->CohesionOff();
	sheep->getSteeringBehavior()->SeparationOff();
}



