#pragma once

#include "IScene.h"

#include "Miner.h"
#include "Graphic.h"
#include "GraphicsMove.h"

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

	Miner bob;
	Miner bob2;
	Miner bob3;
};

