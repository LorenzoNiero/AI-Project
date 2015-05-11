#pragma once

#include "IScene.h"
#include "FontManager.h"
#include <assert.h>
#include <vector>
#include <list>
#include <time.h>
#include <sstream>



class AStarScene : public IScene
{

public:
    
	AStarScene();
    
	virtual void OnIdle(void);
	virtual void OnDraw(sf::RenderWindow&);
    
	virtual ~AStarScene(void);

};


