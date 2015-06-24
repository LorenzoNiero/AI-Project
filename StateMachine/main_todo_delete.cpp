#include "Miner.h"
#include "Graphic.h"
#include "GraphicsMove.h"
#include "Wolf1.h"
#include "Wolf.h"

int main() {

	Miner bob;
	Miner bob2;
	Miner bob3;

	Wolf wolf1;
	
	Graphic gra;
	gra.Initialize();

	GraphicsMove graMove;
	graMove.Initialize();

	bob.setPosition(60.0f, 60.0f);
	bob3.setPosition(40.0f, 50.0f);

	graMove.addActor(&bob);
	graMove.addActor(&bob2);
	graMove.addActor(&bob3);

	while (true){
		
		gra.Draw(bob.getLocation());
		
		graMove.UpdateAgent(); // fa lupdate di tutti gli agent presenti
		graMove.Draw();
				
	}

	return 0;
}

