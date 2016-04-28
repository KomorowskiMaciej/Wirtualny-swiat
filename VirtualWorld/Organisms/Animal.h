#pragma once
#include "Organism.h"


class Animal : public Organism
{

	private:
		int currentDirection = 0;
	public:

		Animal(World * _world, Vector2 l_position):Organism(_world, l_position){
			copulationReady = copulationReadyInterval;
		};
		
		virtual void render() = 0;
		virtual void action();

		int copulationReady = copulationReadyInterval;
		int const copulationReadyInterval = 50;
		void copulation();

		void collision(Organism * l_organism);

		Vector2 moveTo();
};