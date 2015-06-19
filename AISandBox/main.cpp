#include <iostream>
#include "Application.h"

int main(int, char const**)
{
	Application* game = Application::Istance();
	
	game->Init(false);
	
	game->Run();
	
	game->Destroy();
	
	exit(0);
}