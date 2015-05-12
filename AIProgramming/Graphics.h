#pragma once;

#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include "Node.h"

using namespace sf;
using namespace std;

class Graphic{
public:
	Graphic(){};
	~Graphic(){};

	int Initialize(vector<Node> &result);
	void Draw(vector<Node> &result);
	void setTilePosition(vector<Node> &result, vector<Sprite> &sprites);

	vector<Sprite> getSprites() { return sprites; };

private:
	RenderWindow window;
	Texture texture;
	Sprite sprite;
	vector<Sprite> sprites;
};