#include "Zombie.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

int randRange(int min, int max)
{
	srand(time(NULL));
	return rand() % (max - min) + min;
}

void Zombie::init(const char a_name[], const char a_occ[])
{

	sprintf_s(name, "%s", a_name);
	sprintf_s(prior, "%s", a_occ);
	hp = randRange(90, 150);
	attack = randRange(10, 25);
	critRate = randRange(5, 25);
	kills = 0;
}

void Zombie::draw(bool brief) const
{
	printf("%s %s %d\n", name, prior, hp);
	if (!brief)
	{
		printf("Health %d\nAttack: %d\n", hp, attack);
	}

}

bool Zombie::isAlive() const { return hp > 0; }

void Zombie::takeDamage(int dmg) { hp -= dmg; }

int Zombie::rollAttack() const { return attack; }