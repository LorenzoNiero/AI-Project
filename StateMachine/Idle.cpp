#include "Idle.h"

Idle* Idle::m_pIInstance = nullptr;

State<Miner>& Idle::getIInstance()
{
	static Idle theInstance;
	m_pIInstance = &theInstance;
	return *m_pIInstance;
};

void Idle::Enter(Miner* miner){
	std::cout << "Entering HOME" << std::endl;
	miner->setLocation(home);
}

void Idle::Execute(Miner* miner){
	miner->increaseStamina();
	std::cout << miner->getStamina() << std::endl;
	if (miner->getStamina() >= 5000) { 
		miner->getStateMachine()->ChangeState((State<Miner>*)&Walk::getWInstance());
	}
}

void Idle::Exit(Miner* miner){
	std::cout << "Leaving HOME" << std::endl;
<<<<<<< HEAD
}
=======
}

>>>>>>> 75c8efe2055a02c38c37a49ddb2ad19269e72cbe
