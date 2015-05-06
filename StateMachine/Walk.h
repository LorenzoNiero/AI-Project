#pragma once
#include "State.h"
#include "Miner.h"

class Miner;
class Walk : State<Miner> {

private:
	static Walk* m_pWInstance;

public:
	static State<Miner>& getWInstance();
<<<<<<< HEAD
	~Walk() {};
=======
	~Walk(){};
>>>>>>> 75c8efe2055a02c38c37a49ddb2ad19269e72cbe

private :
	Walk(){};

public:
	void Enter(Miner*);
	void Execute(Miner*);
	void Exit(Miner*);
};
