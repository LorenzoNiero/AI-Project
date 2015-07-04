#include "MinerScene.h"


MinerScene::MinerScene()
{
	gra.Initialize();
	graMove.Initialize();

	bob.setPosition(60.0f, 60.0f);
	bob3.setPosition(40.0f, 50.0f);
	
	sheep1.setPosition(600, 150);

	graMove.addActor(&bob);
	graMove.addActor(&bob2);
	graMove.addActor(&bob3);
	graMove.addActor(&wolf1);
	graMove.addActor(&sheep1);
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





