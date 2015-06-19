#pragma once;

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Miner.h"
#include "Agent.h"
#include <vector>
#include "Vector2.h"


class GraphicsMove{
public:
	GraphicsMove(){};
	~GraphicsMove();

	void Initialize(SMnamespace::Vector2);
	void Draw(Miner &miner);
	
	void addActor(Miner *agent);
private:
	sf::Font font;
	//sf::Text textIdle, textWalk, textMining, textCurrentState;
	//sf::CircleShape circleIdle, circleWalk, circleMining, circleCurrentState;
	std::vector<Miner*> *m_VectorAgent;
	std::vector<sf::CircleShape *> *m_VectorCircle;
	sf::Color color;
	sf::RenderWindow window;

	sf::CircleShape minerCircle;
	sf::CircleShape circleHome;
	sf::CircleShape circleMine;

};