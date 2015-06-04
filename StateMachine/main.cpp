#include "Miner.h"
#include "Graphic.h"
#include "GraphicsMove.h"

int main() {

	Miner bob;
	
	Graphic gra;
	gra.Initialize();

	GraphicsMove graMove;
	graMove.Initialize(bob.getPosition());

	//graMove.addActor(bob);

	while (true){
		bob.Update();
		gra.Draw(bob.getLocation());
		graMove.Draw(bob);
				
		//graMove.Draw(bob.getLocation());
	}

	return 0;
}

