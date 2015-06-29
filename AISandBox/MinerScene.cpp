#include "MinerScene.h"


MinerScene::MinerScene()
{
	gra.Initialize();
	graMove.Initialize();

	bob.setPosition(60.0f, 60.0f);
	bob3.setPosition(40.0f, 50.0f);
	
	graMove.addActor(&bob);
	graMove.addActor(&bob2);
	graMove.addActor(&bob3);
}

MinerScene::~MinerScene()
{
    
}

void MinerScene::OnIdle()
{
	//while (true){
		gra.Draw(bob.getLocation());		
		graMove.UpdateAgent(); // fa lupdate di tutti gli agent presenti
		graMove.Draw();
	//}
}

void MinerScene::OnDraw(sf::RenderWindow& renderWindow)
{
    
}





