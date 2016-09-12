/*
1. Create a class representing a zombie.
	Each zombie should have a health and attack value, and a previous occupation.
	Ensure that the zombie's variable are private
		and there are functions to access and modify the zombies' data.

2. Using the zombie class, create a game in which a small number of zombies
	attack each other until only one remains!
*/

#include <cstdio>
#include <cstdlib>
#include "GameState.h"

void main()
{
	GameState gs;
	gs.init();

	gs.start();
	
	while (!gs.isGameOver())
	{
		gs.update();
		gs.drawRound();
	}
	gs.drawWinner();
	getchar();
}