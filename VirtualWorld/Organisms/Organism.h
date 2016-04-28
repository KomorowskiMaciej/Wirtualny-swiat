#pragma once

#include "../utils/Vector2.cpp"
#include "curses.h"
#include <string>
#include <cstdlib>
#include <typeinfo>
#include <ctime>

class World;

class Organism
{	
protected:
	int str;
	int initiative;
	Vector2 position;
	World *p_world;
	int id;

public:
	Organism(World * _world, Vector2 l_position) {
		p_world = _world;
		position = l_position;
	};

	void setPosition(Vector2 pos) {
		position = pos;
	}

	void setInitiative(int ini) {
		initiative = ini;
	}

	void setStrength(int _str) {
		str = _str;
	}

	Vector2 getPosition() {
		return position;
	}

	int getInitiative() {
		return initiative;
	}

	int getStrength() {
		return initiative;
	}

	virtual Organism* Create(World * _world, Vector2 l_position) = 0;
	virtual std::string getName() = 0;

	virtual void action() = 0;
	virtual void collision(Organism * l_organism) = 0;
	virtual void render() = 0;
};