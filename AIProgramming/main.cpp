#include <iostream>
#include "AStar.h"

#include <SFML/Graphics.hpp>

int main(int argc, const char * argv[])
{

	AStar algorithm;
	algorithm.Setup();
	algorithm.Run();
	getchar();

	return 0;
	/*
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(250, 290), "AI gioco del 15");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("cute_image.jpg"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);
	
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();
		// Draw the string
		window.draw(sprite);
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;*/
}