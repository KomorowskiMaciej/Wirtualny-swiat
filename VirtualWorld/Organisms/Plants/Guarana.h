#pragma once

#include "../Plant.h"
#include <iostream>

using namespace std;
class Guarana : public Plant
{
public:
	Guarana(World * _world, Vector2 l_position) : Plant(_world, l_position)
	{
		str = 0;
	}

	Organism* Create(World * _world, Vector2 l_position) {
		return new Guarana(_world, l_position);
	}

	string getName() {
		return "Guarana";
	}

	void render() {
		move(position.x, position.y);
		attron(COLOR_PAIR(4));
		printw("O");
	}
};