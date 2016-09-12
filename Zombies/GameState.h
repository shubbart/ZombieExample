#pragma once
#include "Zombie.h"

class GameState
{

	const int Z_COUNT = 4;
	Zombie zombies[4];

public:
	void init();
	void update();

	void start();
	void drawStatus() const;
	void drawRound() const;
	bool isGameOver() const;
	void drawWinner() const;
};
