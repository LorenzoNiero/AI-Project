#include "GraphicsMove.h"

void GraphicsMove::Initialize() {

	m_VectorAgent = new std::vector<Miner*>();
	m_VectorCircle = new std::vector<sf::CircleShape *>();

	circleHome.setRadius(20.f);
	circleHome.setFillColor(color.Yellow);
	circleHome.setPosition(positionMine.x, positionMine.y);


	window.create(sf::VideoMode(800, 600), "FSM Miner at Work!");
}

void GraphicsMove::Draw() {

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	/*switch (location){
	case home: circleCurrentState.setFillColor(color.Green); break;
	case walking: circleCurrentState.setFillColor(color.Yellow); break;
	case mine: circleCurrentState.setFillColor(color.Red); break;
	default: circleCurrentState.setFillColor(color.White); break;
	}*/

	window.clear();
	window.draw(circleHome);
	/*window.draw(circleIdle);
	window.draw(textIdle);
	window.draw(circleWalk);
	window.draw(textWalk);
	window.draw(circleMining);
	window.draw(textMining);
	window.draw(textCurrentState);
	window.draw(circleCurrentState);*/

	for (int i = 0; i < m_VectorCircle->size(); i++) {
		window.draw(*(m_VectorCircle->at(i)));
	}

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

	for (int i = 0; i < m_VectorCircle->size(); i++) {		
		delete m_VectorAgent->at(i);
		delete m_VectorCircle->at(i);
	}

	delete m_VectorAgent;
	delete m_VectorCircle;
}
