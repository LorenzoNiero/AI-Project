#pragma once

#include "IScene.h"

#include "Miner.h"
#include "Graphic.h"
#include "GraphicsMove.h"
#include "Wolf.h"
#include "Sheep.h"

using namespace SMnamespace;


class MinerScene : public IScene
{
public:

	MinerScene();
	virtual ~MinerScene();
    
	virtual void OnIdle();
	virtual void OnDraw(sf::RenderWindow& renderWindow);

private:
	Graphic gra;
	GraphicsMove graMove;
	
	Wolf wolf1;

	Miner bob;
	Miner bob2;
	Miner bob3;

	std::vector<Agent*> nNeighbors;

	Sheep sheep1;
	Sheep sheep2;
	Sheep sheep3;
};

