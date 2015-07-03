#include "GraphicsMove.h"

void GraphicsMove::Initialize() {

	m_VectorAgent = new std::vector<Agent*>();
	m_VectorCircle = new std::vector<sf::CircleShape *>();

	circleHome.setRadius(20.f);
	circleHome.setFillColor(color.Yellow);
	circleHome.setPosition(positionHome.x, positionHome.y);

	circleMine.setRadius(20.f);
	circleMine.setFillColor(color.Yellow);
	circleMine.setPosition(positionMine.x, positionMine.y);
		
	window.create(sf::VideoMode(800, 600), "FSM Miner at Work!");

	if (!texGnomo.loadFromFile("../StateMachine/Sprites/gnomo.png"))
	{
		// error...
	}
	if (!texCane.loadFromFile("../StateMachine/Sprites/cane.png"))
	{
		// error...
	}
	if (!texMiniera.loadFromFile("../StateMachine/Sprites/miniera.png"))
	{
		// error...
	}
	if (!texCasa.loadFromFile("../StateMachine/Sprites/casa.png"))
	{
		// error...
	}
	sprGnomo.setTexture(texGnomo);
	sprCane.setTexture(texCane);
	sprMiniera.setTexture(texMiniera);
	sprCasa.setTexture(texCasa);
	sprCasa.setPosition((positionHome.x-10), (positionHome.y-50));
	sprCasa.setScale(0.4,0.4);
}

//void GraphicsMove::Draw(Miner& miner) {
//
//	sf::Event event;
//	while (window.pollEvent(event))
//	{
//		if (event.type == sf::Event::Closed)
//			window.close();
//	}
//
//	window.clear();
//	window.draw(circleHome);
//	window.draw(circleMine);
//
//	minerCircle.setPosition(miner.getPosition().x, miner.getPosition().y);
//
//	window.draw(minerCircle);
//	
//	window.display();
//
//}

void GraphicsMove::Draw() {

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	window.clear();
	//window.draw(circleHome);
	window.draw(sprCasa);

	window.draw(circleMine);

	for (int i = 0; i < m_VectorCircle->size(); i++)
	{
		Agent *tmp = m_VectorAgent->at(i);
		sf::CircleShape *tmpCircle = m_VectorCircle->at(i);
					
		tmpCircle->setPosition(tmp->getPosition().x, tmp->getPosition().y);

		window.draw(*tmpCircle);
	}

	window.display();
}

void GraphicsMove::addActor(Agent *agent)
{
	m_VectorAgent->push_back( agent );

	sf::CircleShape *circle = new sf::CircleShape();
	circle->setRadius(10.f);
	circle->setFillColor(color.Red);
	circle->setPosition(agent->getPosition().x, agent->getPosition().y);
	
	m_VectorCircle->push_back(circle);

}

void GraphicsMove::UpdateAgent()
{

	for (int i = 0; i < m_VectorAgent->size(); i++)
	{
		Agent *tmp = m_VectorAgent->at(i);
		tmp->Update();
		
	}

}

GraphicsMove::~GraphicsMove(){

	for (int i = 0; i < m_VectorCircle->size(); i++) {
		delete m_VectorCircle->at(i);
	}

	delete m_VectorAgent;
	delete m_VectorCircle;
}
