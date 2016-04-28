#pragma once
#include "Organism.h"

class OrganismMatrix
{
public:

	OrganismMatrix(Vector2 l_worldSize) {
		organismCounter = 0;
		worldSize = l_worldSize;
		maxOrganisms = worldSize.x * worldSize.y;
		positionMatrix = new Organism **[worldSize.y];
		for (int i = 0; i < worldSize.y+1; i++)
		{
			positionMatrix[i] = new Organism *[worldSize.x];
			for (int j = 0; j < worldSize.x+1; j++)
				positionMatrix[i][j] = nullptr;
		}
	}

	int organismCounter;
	int maxOrganisms;
	Vector2 worldSize;

	void removeOrganismInPosition(Vector2 position) {
		if (positionMatrix[position.y][position.x])
			delete positionMatrix[position.y][position.x];
		positionMatrix[position.y][position.x] = nullptr;
	};

	void moveOrganism(Vector2 from, Vector2 to) {
		setOrganismInPosition(to, getOrganismInPosition(from));
		positionMatrix[from.y][from.x] = nullptr;
	};

	void setOrganismInPosition(Vector2 position, Organism * _organism) {
		if (positionMatrix[position.y][position.x]) 
		{
			delete positionMatrix[position.y][position.y];
			positionMatrix[position.y][position.x] = nullptr;
		}
		positionMatrix[position.y][position.x] = _organism;
		if(_organism) {
			_organism->setPosition(position);
		}
	};

	Organism* getOrganismInPosition(Vector2 position) {
		return positionMatrix[position.y][position.x];
	};

private:
	Organism*** positionMatrix;
};