#pragma once
#include "../Plant.h"
#include <iostream>

using namespace std;
class SawThistles : public Plant
{
public:
	SawThistles(World * _world, Vector2 l_position) : Plant(_world, l_position)
	{
		str = 0;
	}

	Organism* Create(World * _world, Vector2 l_position) {
		return new SawThistles(_world, l_position);
	}

	string getName() {
		return "Saw thistles";
	}

	void render() {
		move(position.x, position.y);
		attron(COLOR_PAIR(5));
		printw("O");
	}

	void action() {
		if (rand() % 40 == 0)
			copulation();
		if (rand() % 40 == 0)
			copulation();
		if (rand() % 40 == 0)
			copulation();
	}
};