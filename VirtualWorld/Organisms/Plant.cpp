#include "Plant.h"
#include "../World.h";

void Plant::copulation() {

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
}