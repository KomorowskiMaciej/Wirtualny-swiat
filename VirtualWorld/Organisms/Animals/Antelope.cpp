#include "Antelope.h"
#include "../World.h"

void Antelope::action() {
	if (copulationReady > -1)
		copulationReady--;
	Organism* p_organism = nullptr;
	Vector2 movePosition = moveTo();
	p_organism = p_world->getOrganismMatrix()->getOrganismInPosition(movePosition);

	if (!p_organism) {
		p_world->getOrganismMatrix()->moveOrganism(position, movePosition);

		movePosition = moveTo();
		p_organism = p_world->getOrganismMatrix()->getOrganismInPosition(movePosition);

		if (!p_organism)
			p_world->getOrganismMatrix()->moveOrganism(position, movePosition);
		else collision(p_organism);
	}
	else collision(p_organism);
}