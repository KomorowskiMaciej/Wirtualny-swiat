#include "Animal.h"
#include "../World.h";

void Animal::copulation() {


	if(copulationReady < 0){
		if (
			this->position.x + 1 < p_world->getOrganismMatrix()->worldSize.x &&
			!p_world->getOrganismMatrix()->getOrganismInPosition(Vector2(this->position.x + 1, this->position.y)))

			p_world->getOrganismMatrix()->setOrganismInPosition(Vector2(this->position.x + 1, this->position.y), this->Create(p_world, Vector2(this->position.x + 1, this->position.y)));
		else 
		if (this->position.y + 1 < p_world->getOrganismMatrix()->worldSize.y &&
			!p_world->getOrganismMatrix()->getOrganismInPosition(Vector2(this->position.x, this->position.y + 1)))
		
			p_world->getOrganismMatrix()->setOrganismInPosition(Vector2(this->position.x, this->position.y + 1), this->Create(p_world, Vector2(this->position.x, this->position.y + 1)));
		else 
		if (this->position.x - 1 > 0 &&
			!p_world->getOrganismMatrix()->getOrganismInPosition(Vector2(this->position.x - 1, this->position.y)))

			p_world->getOrganismMatrix()->setOrganismInPosition(Vector2(position.x - 1, position.y), this->Create(p_world, Vector2(this->position.x - 1, this->position.y)));
		else 
		if (this->position.y - 1 > 0 &&
			!p_world->getOrganismMatrix()->getOrganismInPosition(Vector2(this->position.x, this->position.y - 1)))

			p_world->getOrganismMatrix()->setOrganismInPosition(Vector2(position.x, position.y - 1), this->Create(p_world, Vector2(position.x, position.y - 1)));

		copulationReady = copulationReadyInterval;
	}
}

void Animal::collision(Organism * l_organism) {

	if (typeid(*l_organism) == typeid(*this)) {
		if (this->getName() != "Human")
			copulation();
	}
	else {
		
		if (l_organism->getName() == "Tortoise" && this->str < 5)
			return;

		if (l_organism->getName() == "Belladona") {		
			p_world->addEvent(this->getName() + " ate " + l_organism->getName() + ".");
			p_world->getOrganismMatrix()->removeOrganismInPosition(l_organism->getPosition());
			p_world->getOrganismMatrix()->removeOrganismInPosition(this->position);
			return;
		}

		if ((l_organism->getName() == "Antelope" || this->getName() == "Antelope" ) && rand() % 2 == 0) {
			return;
		}

		if (l_organism->getName() == "Guarana") {
			str += 3;
		}

		if (l_organism->getStrength() <= this->str){
			p_world->getOrganismMatrix()->removeOrganismInPosition(l_organism->getPosition());
		} else { 
			p_world->addEvent(l_organism->getName() + " killed " + this->getName() + ".");
			p_world->getOrganismMatrix()->removeOrganismInPosition(this->position);
		}
	}
}


void Animal::action() {
	if(copulationReady > -1)
		copulationReady--;
	Organism* p_organism = nullptr;
	Vector2 movePosition = moveTo();
	p_organism = p_world->getOrganismMatrix()->getOrganismInPosition(movePosition);

	if (!p_organism) {
		p_world->getOrganismMatrix()->moveOrganism(position, movePosition);
	}
	else collision(p_organism);
}

Vector2 Animal::moveTo() {

	Vector2 newPosition(position.x, position.y);

	switch (rand() % 4)
	{
	case 0:
		if (position.y > 0) {
			newPosition.y--;
		}
		else {
			newPosition.y++;
		}
		currentDirection = 0;
		break;
	case 1:
		if (position.y < p_world->getOrganismMatrix()->worldSize.y) {
			newPosition.y++;
		}
		else {
			newPosition.y--;
		}
		currentDirection = 1;
		break;
	case 2:
		if (position.x < p_world->getOrganismMatrix()->worldSize.x) {
			newPosition.x++;
		}
		else {
			newPosition.x--;
		}
		currentDirection = 2;
		break;
	case 3:
		if (position.x > 0) {
			newPosition.x--;
		}
		else {
			newPosition.x++;
		}
		currentDirection = 3;
		break;
		default:
			break;
	}
	return newPosition;
}