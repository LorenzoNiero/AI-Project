#include "Miner.h"
#include "Graphic.h"
#include "GraphicsMove.h"

int main() {

	Miner *bob= new Miner();
	Graphic gra;
	gra.Initialize();

	GraphicsMove graMove;
	graMove.Initialize();

	graMove.addActor(bob);

	while (true){
		bob->Update();
		gra.Draw(bob->getLocation());
		graMove.Draw();

		
		//graMove.Draw(bob.getLocation());
	}

	return 0;
}

