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

	void Initialize();
	
	// deprecato
	//void Draw( Miner &miner );	
	void Draw();
	void addActor(Agent *agent);

	void UpdateAgent();
private:
	sf::Font font;
	//sf::Text textIdle, textWalk, textMining, textCurrentState;
	//sf::CircleShape circleIdle, circleWalk, circleMining, circleCurrentState;
	std::vector<Agent*> *m_VectorAgent;
	std::vector<sf::CircleShape *> *m_VectorCircle;
	sf::Color color;
	sf::RenderWindow window;

	sf::CircleShape minerCircle;
	sf::CircleShape circleHome;
	sf::CircleShape circleMine;

	sf::Texture texGnomo;
	sf::Texture texCane;
	sf::Texture texMiniera;
	sf::Texture texCasa;

	sf::Sprite sprGnomo;
	sf::Sprite sprCane;
	sf::Sprite sprMiniera;
	sf::Sprite sprCasa;
};