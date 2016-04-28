#include "Tortoise.h"
#include "../World.h"


void Tortoise::update() {
	if (copulationReady > -1)
		copulationReady--;
	Organism* p_organism = nullptr;
	Vector2 movePosition = moveTo();
	p_organism = p_world->getOrganismMatrix()->getOrganismInPosition(movePosition);
	if (rand() % 4 == 0) {
		if (!p_organism) {
			p_world->getOrganismMatrix()->moveOrganism(position, movePosition);
		}
		else collision(p_organism);
	}
}