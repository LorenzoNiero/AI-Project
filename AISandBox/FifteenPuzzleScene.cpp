#include "FifteenPuzzleScene.h"

FifteenPuzzleScene::FifteenPuzzleScene()
{
	
	algorithm.Setup();
	graphic.Initialize(result);
}

FifteenPuzzleScene::~FifteenPuzzleScene()
{
    
}

void FifteenPuzzleScene::OnIdle()
{
	algorithm.Run(result);
	graphic.Draw(result);
}

void FifteenPuzzleScene::OnDraw(sf::RenderWindow& renderWindow)
{
    
}