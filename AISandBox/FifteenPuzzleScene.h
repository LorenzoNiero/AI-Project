#pragma once

#include "IScene.h"
#include <algorithm>
#include <sstream>
#include "FontManager.h"


class FifteenPuzzleScene : public IScene
{
    
public:

	FifteenPuzzleScene();


    virtual void OnIdle();
    virtual void OnDraw(sf::RenderWindow&);

	virtual ~FifteenPuzzleScene();
};