#include "MinerScene.h"


MinerScene::MinerScene()
{
	gra.Initialize();
	graMove.Initialize(bob.getPosition());
}

MinerScene::~MinerScene()
{
    
}

void MinerScene::OnIdle()
{
	while (true){
		bob.Update();
		gra.Draw(bob.getLocation());
		graMove.Draw(bob);
				
		//graMove.Draw(bob.getLocation());
	}
}

void MinerScene::OnDraw(sf::RenderWindow& renderWindow)
{
    
}





