#include "GraphicsMove.h"

void GraphicsMove::Initialize() {

	m_VectorAgent = new std::vector<Agent*>();
	m_VectorCircle = new std::vector<sf::CircleShape *>();

	window.create(sf::VideoMode(800, 600), "FSM Miner at Work!");

	if (!texGnomo.loadFromFile("../StateMachine/Sprites/gnomo.png"))
	{
		// error...
	}
	if (!texCane.loadFromFile("../StateMachine/Sprites/cane.png"))
	{
		// error...
	}
	if (!texSheep.loadFromFile("../StateMachine/Sprites/sheep.png"))
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
	
	sprCasa.setTexture(texCasa);
	sprCasa.setPosition((positionHome.x-10), (positionHome.y-50));
	sprCasa.setScale(0.4,0.4);

	sprMiniera.setTexture(texMiniera);
	sprMiniera.setPosition((positionMine.x-50), (positionMine.y-50));
	sprMiniera.setScale(0.4, 0.4);

	sprGnomo.setTexture(texGnomo);
	sprGnomo.setScale(0.3, 0.3);

	sprCane.setTexture(texCane);
	sprCane.setScale(0.2, 0.2);

	sprSheep.setTexture(texSheep);
	sprSheep.setScale(0.4, 0.4);

	//circleEnclosure.setPosition(0, 0);
	
	circleEnclosure.setRadius(radiusEnclosure);
	circleEnclosure.setOrigin(radiusEnclosure, radiusEnclosure);
	circleEnclosure.setFillColor(color.Blue);
	//circleEnclosure.setPosition(0, 0);
	circleEnclosure.setPosition(enclosureCenter.x , enclosureCenter.y);

	circleLimitWolf.setRadius(LimitDistanceWolf);
	circleLimitWolf.setOrigin(LimitDistanceWolf, LimitDistanceWolf);
	circleLimitWolf.setFillColor(color.Cyan);
	//circleLimitWolf.setPosition(0,0);
	circleLimitWolf.setPosition(enclosureCenter.x , enclosureCenter.y  );
}

void GraphicsMove::Draw() {

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	window.clear();
	window.draw(sprCasa);
	window.draw(sprMiniera);
	window.draw(circleLimitWolf);
	window.draw(circleEnclosure);
	

	for (int i = 0; i < m_VectorCircle->size(); i++)
	{
		Agent *tmp = m_VectorAgent->at(i);
		sf::CircleShape *tmpCircle = m_VectorCircle->at(i);
					
		tmpCircle->setPosition(tmp->getPosition().x, tmp->getPosition().y);

		if (tmp->GetAgentType() == GNOME)
		{
			sprGnomo.setPosition(tmpCircle->getPosition().x, tmpCircle->getPosition().y);
			window.draw(sprGnomo);
		}
		else if (tmp->GetAgentType() == SHEEP)
		{
			sprSheep.setPosition(tmpCircle->getPosition().x, tmpCircle->getPosition().y);
			window.draw(sprSheep);
		}
		else if (tmp->GetAgentType() == DOG)
		{
			sprCane.setPosition(tmpCircle->getPosition().x, tmpCircle->getPosition().y);
			window.draw(sprCane);
		}
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

	for (int i = 0; i < m_VectorCircle->size(); i++) 
	{
		delete m_VectorCircle->at(i);
	}

	delete m_VectorAgent;
	delete m_VectorCircle;
}
