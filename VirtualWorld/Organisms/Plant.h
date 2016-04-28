#pragma once
#include "Organism.h"

class Plant : public Organism
{

public:
	void copulation();
	Plant(World * _world, Vector2 l_position) :Organism(_world, l_position) {
		initiative = 0;
	}
	void action() {
		if (rand() % 20 == 0)
				copulation();
	}

	void collision(Organism * l_organism) {
	}
};
