#include "Miner.h"
#include "Graphic.h"

int main() {

	Miner bob;
	Graphic gra;
	gra.Initialize();

	while (true){
		bob.Update();
		gra.Draw(bob.getLocation());
	}

	return 0;
}

