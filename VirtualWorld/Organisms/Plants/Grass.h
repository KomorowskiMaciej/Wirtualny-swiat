#pragma once

#include "../Plant.h"
#include "curses.h"

class Grass : public Plant
{
public:
	Grass(World * _world, Vector2 l_position) : Plant(_world, l_position)
	{
		str = 0;
	}

	Organism* Create(World * _world, Vector2 l_position) {
		return new Grass(_world, l_position);
	}

	string getName() {
		return "Grass";
	}

	void render() {
		move(position.x, position.y);
		attron(COLOR_PAIR(1));
		printw("#");
	}

};