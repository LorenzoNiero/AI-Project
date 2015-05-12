#include "AStarScene.h"
#include "AStar.h"
#include "Application.h"

/*
Setto le posizioni dei quadrati
*/
void AStarScene::setTilePosition(std::vector<RectangleShape> &sprites)
{
		
	for (int index = 0; index < 100; ++index){

		sprites.at(index).setPosition((index/10)* 50.0f, (index%10)* 50.0f);
		
	}
	
}

AStarScene::AStarScene()
{
	/*AStar alg;
	alg.Run();*/
	
	for (int index = 0; index < 100; ++index)
	{
		//creo quadrato
		sf::RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f(50, 50));
		rectangle.setOutlineColor(sf::Color::Red);
		rectangle.setFillColor(sf::Color::Blue);
		rectangle.setOutlineThickness(1);
		rectangle.setPosition(0, 0);
			
		//inserisco alla fine dell array	
		sprites.push_back(rectangle);
		
	}

	setTilePosition( sprites);

}



AStarScene::~AStarScene()
{
    
}

/*
usere per intercettare eevnti tastiera o mouse ecc
*/
void AStarScene::OnIdle()
{
	//Application::Istance()->SetScene(SceneEnum::Scene_MainMenu);
}


/*
Questo è il metodo che viene chiamato ogni frame
Creato dal prof
*/
void AStarScene::OnDraw(sf::RenderWindow& renderWindow)
{
	
	for (int index = 0; index < 100; ++index){
		renderWindow.draw(sprites[index]);
	}

}
