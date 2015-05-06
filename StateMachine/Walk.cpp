#include "Walk.h"

Walk* Walk::m_pWInstance = nullptr;

State<Miner>& Walk::getWInstance()
{
	static Walk theInstance;
	m_pWInstance = &theInstance;
	return *m_pWInstance;
};

void Walk::Enter(Miner* miner){
	std::cout << "WALKING START" << std::endl;
	miner->resetKlm();
	miner->setFromLocation(miner->getLocation());
	miner->setLocation(walking);
}

void Walk::Execute(Miner* miner){
	miner->decreaseKlm();
	std::cout << miner->getKlm() << std::endl;
	if (miner->getKlm() < 0) {
		switch (miner->getFromLocation())
		{
		case home: miner->getStateMachine()->ChangeState(&Mining::getMInstance()); break;
		case mine: miner->getStateMachine()->ChangeState(&Idle::getIInstance()); break;
		default:
			break;
		}
	}
}

void Walk::Exit(Miner* miner){
	std::cout << "WALKING END" << std::endl;
}

