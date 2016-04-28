#pragma once

#include "../Animal.h"
#include <iostream>

using namespace std;
class Sheep : public Animal
{
public:
	Sheep(World * _world, Vector2 l_position) : Animal(_world, l_position)
	{
		str = 4;
		initiative = 4;
	}

	string getName() {
		return "Sheep";
	}


	Organism* Create(World * _world, Vector2 l_position) {
		return new Sheep(_world, l_position);
	}

	void render() {
		move(position.x, position.y);
		attron(COLOR_PAIR(2));
		printw("S");
	}


};