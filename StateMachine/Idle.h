#pragma once
#include "State.h"
#include "Miner.h"
#include "Walk.h"

class Miner;
class Idle : State<Miner>{

private:
	static Idle* m_pIInstance;

public:
	static State<Miner>& getIInstance();
<<<<<<< HEAD
	~Idle() {};
=======
	~Idle(){};
>>>>>>> 75c8efe2055a02c38c37a49ddb2ad19269e72cbe

private:
	Idle() {};

public:
	void Enter(Miner*);
	void Execute(Miner*);
	void Exit(Miner*);
};
