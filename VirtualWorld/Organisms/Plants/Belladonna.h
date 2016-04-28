#pragma once
#include "../Plant.h"
#include <iostream>

using namespace std;
class Belladona : public Plant
{
	public:

		Belladona(World * _world, Vector2 l_position) : Plant(_world, l_position)
		{
			str = 99;
		}

		Organism* Create(World * _world, Vector2 l_position) {
			return new Belladona(_world, l_position);
		}

		string getName() {
			return "Belladona";
		}

	void render() {
		move(position.x, position.y);
		attron(COLOR_PAIR(7));
		printw("O");
	}

	void action() {
		if (rand() % 200 == 0)
			copulation();
	}

};