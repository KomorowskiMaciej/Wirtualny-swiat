#pragma once

#include "../Animal.h"
#include <iostream>

using namespace std;
class Tortoise : public Animal
{
public:
	Tortoise(World * _world, Vector2 l_position) : Animal(_world, l_position)
	{
		str = 2;
		initiative = 1;
	}

	
	string getName() {
		return "Tortoise";
	}

	Organism* Create(World * _world, Vector2 l_position) {
		return new Tortoise(_world, l_position);
	}

	void update();

	void render() {
		move(position.x, position.y);
		attron(COLOR_PAIR(2));
		printw("T");
	}
};
