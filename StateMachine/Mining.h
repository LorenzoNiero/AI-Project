#pragma once
#include "State.h"
#include "Miner.h"

class Miner;
class Mining : State<Miner> {

private:
	static Mining* m_pMInstance;

public:
	static State<Miner>& getMInstance();
<<<<<<< HEAD
	~Mining() {};
=======
	~Mining(){};
>>>>>>> 75c8efe2055a02c38c37a49ddb2ad19269e72cbe

private:
	Mining(){};

public:
	void Enter(Miner*);
	void Execute(Miner*);
	void Exit(Miner*);
};
