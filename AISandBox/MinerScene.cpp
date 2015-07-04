#include "MinerScene.h"


MinerScene::MinerScene()
{
	gra.Initialize();
	graMove.Initialize();

	bob.setPosition(60.0f, 60.0f);
	bob3.setPosition(40.0f, 50.0f);
	
	sheep1.setPosition(enclosureCenter.x, enclosureCenter.y);
	sheep2.setPosition(enclosureCenter.x + 5, enclosureCenter.y);
	sheep3.setPosition(enclosureCenter.x + 5, enclosureCenter.y+5);

	graMove.addActor(&bob);
	graMove.addActor(&bob2);
	graMove.addActor(&bob3);
	graMove.addActor(&wolf1);
	graMove.addActor(&sheep1);
	graMove.addActor(&sheep2);
	graMove.addActor(&sheep3);
}

MinerScene::~MinerScene()
{
}

void MinerScene::OnIdle()
{
}

void MinerScene::OnDraw(sf::RenderWindow& renderWindow)
{
	gra.Draw(bob.getLocation());
	graMove.UpdateAgent(); // fa lupdate di tutti gli agent presenti
	graMove.Draw();
}





