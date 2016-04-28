#pragma once

#include "../Animal.h"
#include <iostream>

using namespace std;
class Human : public Animal
{
private:
	void activeSpecial();
	int activatedPower;
public:
	Human(World * _world, Vector2 l_position) : Animal(_world, l_position)
	{
		str = 5;
		initiative = 4;
		activatedPower = 0;
	}

	string getName() {
		return "Human";
	}


	Organism* Create(World * _world, Vector2 l_position) {
		return new Human(_world, l_position);
	}

	void render() {
		move(position.x, position.y);
		attron(COLOR_PAIR(4));
		printw("X");
	}

	void copulation() {
	
	};

	void action();
};