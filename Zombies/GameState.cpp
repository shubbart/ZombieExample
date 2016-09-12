#include "GameState.h"
#include <cstdio>
#include <cstdlib>

void GameState::init()
{
	zombies[0].init("Sally", "Librarian");
	zombies[1].init("Milly"  , "Butcher");
	zombies[2].init("Sam"     , "Tailor");
	zombies[3].init("Spot"     , "T-Rex");
}


void GameState::start()
{
	drawStatus();
	printf("\nLet the battle begin!\n");
}
void GameState::drawStatus() const
{
	for (int i = 0; i < 4; ++i)
		zombies[1].draw(false);
}

void GameState::drawRound() const
{
	printf("\n####Combat Round:#### \n");
	for (int i = 0; i < Z_COUNT; ++i)
		zombies[i].draw(true);
}

void GameState::update()
{
	for (int i = 0; i < Z_COUNT; ++i)
		if (zombies[i].isAlive())
			zombies[rand() % Z_COUNT].takeDamage(zombies[i].rollAttack());
}

bool GameState::isGameOver() const
{
	int livingZombies = 0;
	for (int i = 0; i < Z_COUNT; ++i)
		if (zombies[i].isAlive())
			livingZombies++;


	return livingZombies == 1;
}

void GameState::drawWinner() const
{
	printf("#### The battle is over!! ####\n");
	for (int i = 0; i < Z_COUNT; ++i)
		if (zombies[i].isAlive())
			zombies[i].draw(false);
	printf("The victor has emerged!");
}