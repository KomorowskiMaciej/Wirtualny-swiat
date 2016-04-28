#pragma once

#include "../Animal.h"

using namespace std;
class Antelope : public Animal
{
public:
	Antelope(World * _world, Vector2 l_position) : Animal(_world, l_position)
	{
		str = 4;
		initiative = 4;
	}

	string getName(){
		return "Antelope";
	}


	Organism* Create(World * _world, Vector2 l_position) {
		return new Antelope(_world, l_position);
	}

	virtual void action();

	void render() {
		move(position.x, position.y);
		attron(COLOR_PAIR(2));
		printw("A");
	}
};