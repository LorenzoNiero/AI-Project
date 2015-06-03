#pragma once

#include "Agent.h"
#include "MinerStateMachine.h"
#include "Idle.h"
#include "Walk.h"
#include "Mining.h"
#include "Vector2.h"


const Vector2 positionMine(750, 50);
const Vector2 positionHome(50, 50);

enum location_type{
	home,
	walking,
	mine
};
class MinerStateMachine;
class Miner : public Agent {
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

	location_type getFromLocation() { return m_efromLocation; };
	void setFromLocation(location_type newLocation) { m_efromLocation = newLocation; };

	int getKlm() { return m_iklm; }
	void resetKlm() { m_iklm = 10000; }
	
private:
	MinerStateMachine* m_pMinerStateMachine;
	location_type m_eLocation,m_efromLocation;
	int m_istamina;
	int m_iklm;
	
};