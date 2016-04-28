#pragma once

#include "../Animal.h"
#include <iostream>

using namespace std;
class Fox : public Animal
{
public:
	Fox(World * _world, Vector2 l_position) : Animal(_world, l_position)
	{
		str = 3;
		initiative = 7;
	}

	string getName() {
		return "Fox";
	}

	Organism* Create(World * _world, Vector2 l_position) {
		return new Fox(_world, l_position);
	}


	void render() {
		move(position.x, position.y);
		attron(COLOR_PAIR(2));
		printw("F");
	}
};