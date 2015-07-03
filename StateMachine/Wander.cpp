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
	


	//std::cout << "Update Cane execute " << std::endl;

}

void Wander::Exit(Wolf* wolf){
	std::cout << "Exit Wander Wolf" << std::endl;
	wolf->getSteeringBehavior()->WanderOff();

}

