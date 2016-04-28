#pragma once

#include "Organisms/Organism.h";
#include "utils/Vector2.cpp";

class Organism;

struct WorldStorage
{

	WorldStorage(Vector2 l_worldSize) {
		worldSize = l_worldSize;
		organismCounter = 0;
		organismNextId = 0;
		maxOrganisms = worldSize.y*worldSize.x + 1;
		Organisms = new Organism*[maxOrganisms];
		for (int i = 0; i < maxOrganisms; i++)
			Organisms[i] = nullptr;
	}

	Organism **Organisms;
	Vector2 worldSize;
	int organismCounter = 0;
	int organismNextId = 0;
	int maxOrganisms;
};