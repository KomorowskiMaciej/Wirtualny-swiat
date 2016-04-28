#pragma once

#include "../Animal.h"
#include <iostream>

using namespace std;
class Wolf : public Animal
{
public:
	
	Wolf(World * _world, Vector2 l_position) : Animal(_world, l_position)
	{
		str = 9;
		initiative = 4;
	}

	string getName() {
		return "Wolf";
	}

	Organism* Create(World * _world, Vector2 l_position) {
		return new Wolf(_world, l_position);
	}

	void render() {
		move(position.x, position.y);
		attron(COLOR_PAIR(2));
		printw("W");
	}
};