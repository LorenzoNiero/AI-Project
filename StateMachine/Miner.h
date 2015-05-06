#pragma once

#include "Agent.h"
#include "MinerStateMachine.h"
#include "Idle.h"
#include "Walk.h"
#include "Mining.h"

enum location_type{
	home,
	walking,
	mine
};
class MinerStateMachine;
class Miner : Agent {
public:
	Miner();
	~Miner(){ delete m_pMinerStateMachine;	};

	void Update();
	void increaseStamina() { m_istamina++; };
	void decreaseStamina() { m_istamina--; };
	void decreaseKlm() { m_iklm--;  };
	
	MinerStateMachine* getStateMachine() { return m_pMinerStateMachine; };
	int getStamina() { return m_istamina; };
	location_type getLocation() { return m_eLocation; };
	void setLocation(location_type newLocation) { m_eLocation = newLocation; };
	int getKlm() { return m_iklm; }
	void resetKlm() { m_iklm = 100; }

private:
	MinerStateMachine* m_pMinerStateMachine;
	location_type m_eLocation;
	int m_istamina;
	int m_iklm;
};