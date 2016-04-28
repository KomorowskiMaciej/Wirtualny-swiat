#include "Human.h"
#include "../World.h"


void Human::activeSpecial() {
	activatedPower = 5;
}

void Human::action() {


	Organism* p_organism = nullptr;
	Vector2 humanMoveDirection = p_world->getHumanMovePosition();
	Vector2 movePosition = Vector2(position.x + humanMoveDirection.x, position.y + humanMoveDirection.y);
	p_world->setHumanMovePosition(Vector2(0, 0));
	p_world->setMovePositionComment("");
	p_organism = p_world->getOrganismMatrix()->getOrganismInPosition(movePosition);


	if (activatedPower>2) {
		p_world->getOrganismMatrix()->moveOrganism(position, movePosition);
	}



	if (!p_organism) {

	}
	else collision(p_organism);
}