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
	void Draw();
	void addActor(Agent *agent);

	void UpdateAgent();
private:
	sf::Font font;
	std::vector<Agent*> *m_VectorAgent;
	std::vector<sf::CircleShape *> *m_VectorCircle;
	sf::Color color;
	sf::RenderWindow window;

	sf::CircleShape minerCircle;
	sf::CircleShape circleHome;
	sf::CircleShape circleMine;
	sf::CircleShape circleEnclosure;
	sf::CircleShape circleLimitWolf;

	sf::Texture texGnomo;
	sf::Texture texCane;
	sf::Texture texSheep;
	sf::Texture texMiniera;
	sf::Texture texCasa;

	sf::Sprite sprGnomo;
	sf::Sprite sprCane;
	sf::Sprite sprSheep;
	sf::Sprite sprMiniera;
	sf::Sprite sprCasa;
};