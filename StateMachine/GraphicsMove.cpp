#include "GraphicsMove.h"

void GraphicsMove::Initialize() {

	m_VectorAgent = new std::vector<Miner*>();
	m_VectorCircle = new std::vector<sf::CircleShape *>();

	circleHome.setRadius(20.f);
	circleHome.setFillColor(color.Yellow);
	circleHome.setPosition(positionHome.x, positionHome.y);

	circleHome.setRadius(20.f);
	circleHome.setFillColor(color.Yellow);
	circleHome.setPosition(positionMine.x, positionMine.y);

	minerCircle.setRadius(20.f);
	minerCircle.setFillColor(color.Blue);
	minerCircle.setPosition(0, 0);

	window.create(sf::VideoMode(800, 600), "FSM Miner at Work!");
}

void GraphicsMove::Draw(Miner& miner) {

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	window.clear();
	window.draw(circleHome);
	window.draw(circleMine);

	minerCircle.setPosition(miner.getPosition().x, miner.getPosition().y);

	window.draw(minerCircle);
	
	window.display();

}

void GraphicsMove::addActor(Miner *agent)
{
	m_VectorAgent->push_back( agent );

	sf::CircleShape *circle = new sf::CircleShape();
	circle->setRadius(20.f);
	circle->setFillColor(color.Magenta);
	circle->setPosition(agent->getPosition().x, agent->getPosition().y);
	
	m_VectorCircle->push_back(circle);

}

GraphicsMove::~GraphicsMove(){

	/*for (int i = 0; i < m_VectorCircle->size(); i++) {		
		delete m_VectorAgent->at(i);
		delete m_VectorCircle->at(i);
	}

	delete m_VectorAgent;
	delete m_VectorCircle;*/
}
