#include "Mining.h"

Mining* Mining::m_pMInstance = nullptr;

State<Miner>& Mining::getMInstance()
{
	static Mining theInstance;
	m_pMInstance = &theInstance;
	return *m_pMInstance;
};

void Mining::Enter(Miner* miner){
	std::cout << "Entering MINE" << std::endl;
	miner->setLocation(mine);
}

void Mining::Execute(Miner* miner){
	miner->decreaseStamina();
	std::cout << miner->getStamina() << std::endl;
	if (miner->getStamina() == 0) {
		miner->getStateMachine()->ChangeState((State<Miner>*)&Walk::getWInstance());
	}
}

void Mining::Exit(Miner* miner){
	std::cout << "Leaving MINE" << std::endl;
<<<<<<< HEAD
}
=======
}

>>>>>>> 75c8efe2055a02c38c37a49ddb2ad19269e72cbe
