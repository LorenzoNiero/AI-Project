#pragma once

#include "IScene.h"
#include "FontManager.h"
#include <assert.h>
#include <vector>
#include <list>
#include <time.h>
#include <sstream>
#include <SFML\Graphics.hpp>

using namespace sf;



class AStarScene : public IScene
{

public:
    
	AStarScene();
    
	virtual void OnIdle(void);
	virtual void OnDraw(sf::RenderWindow&);
    
	virtual ~AStarScene(void);

	void setTilePosition(std::vector<RectangleShape> &sprites);

private:
	sf::Texture texture;
	std::vector<sf::RectangleShape> sprites;
	RectangleShape rect;
	//sf::Sprite sprite;
	

};


