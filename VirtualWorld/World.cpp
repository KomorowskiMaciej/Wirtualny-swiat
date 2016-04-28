#include "World.h"
#include <windows.h>
#include <string>
#define tickTime 4
#define debugMode 0


using namespace std;


Vector2 World::getHumanMovePosition() {
	return humanMovePosition;
};

std::string World::getMovePositionComment() {
	return humanMovePositionComment;
};

OrganismMatrix* World::getOrganismMatrix() {
	return organismMatrix;
}

void World::setHumanMovePosition(Vector2 vec) {
	humanMovePosition = vec;
}

void World::setMovePositionComment(std::string comment) {
	humanMovePositionComment = comment;
}

void World::update() {
	for (int z = 9; z >= 0; z--)
	{
		for (int i = 0; i < organismMatrix->worldSize.y; i++) {
			for (int j = 0; j < organismMatrix->worldSize.x; j++) {
				Organism* tmp = organismMatrix->getOrganismInPosition(Vector2(j, i));
				if (tmp) {
					if(tmp->getInitiative() == z) {
							tmp->setPosition(Vector2(j, i));
							tmp->action();
					
					}
				}
			}
		}
	}
}

void World::loop() {
	int input = 0;
	do {

#if debugMode
		update();
		render();
		Sleep(tickTime);
#else		
		input = getch();
		if (input == ' ') {
			update();
			render();
		} else{

		//prawo
		if (input == 'd') {
			this->setHumanMovePosition(Vector2(0,1));
			this->setMovePositionComment("Ruszysz sie w prawo.        ");
		}
			
		//lewo
		if (input == 'a') {
			this->setHumanMovePosition(Vector2(0, -1));
			this->setMovePositionComment("Ruszysz sie w lewo.        ");
		}
		//gora
		if (input == 'w') {
			this->setHumanMovePosition(Vector2(-1, 0));
			this->setMovePositionComment("Ruszysz sie w gore.        ");
		}
			
		//dol
		if (input == 's'){
			this->setHumanMovePosition(Vector2(1, 0));
			this->setMovePositionComment("Ruszysz sie w dol.        ");
		}
			move(organismMatrix->worldSize.y +6, 1);
			printw("%s", this->getMovePositionComment().c_str());
			refresh();
		}
#endif
	} while (input != 'q');
}

void World::addEvent(string _event) {
	if (events.length() > 100)
		events = events.substr(0,100);
	events = _event + "\n " + events;
}

void World::render() {
	clear();
	for (int i = 0; i < organismMatrix->worldSize.y + 1; i++)
	{
		for (int j = 0; j < organismMatrix->worldSize.x + 1; j++)
		{
			move(j, i);
			attron(COLOR_PAIR(1));
			printw(" ");
		}
	}
	attron(COLOR_PAIR(2));

	for (int i = 0; i < organismMatrix->worldSize.y; i++)
		for (int j = 0; j < organismMatrix->worldSize.x; j++)
		{
			Organism* tmp = organismMatrix->getOrganismInPosition(Vector2(j, i));
			if (tmp)
				tmp->render();
		}
	
	attron(COLOR_PAIR(6));
	move(organismMatrix->worldSize.y + 4, 1);
	printw("Maciej Komorowski s160822");
	move(organismMatrix->worldSize.y + 5, 1);
	printw("Amount of organisms: %d/%d", organismMatrix->organismCounter, organismMatrix->maxOrganisms);
	move(organismMatrix->worldSize.y + 6, 1);
	printw("%s", getMovePositionComment().c_str());
	move(organismMatrix->worldSize.y + 7, 1);
	printw("Last events: \n ");
	printw("%s", events.c_str());
	refresh();
}

void World::prepare() {
	srand(time(NULL));
	start_color();


	init_color(COLOR_YELLOW, 667, 333, 0);
	
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	init_pair(7, COLOR_BLUE, COLOR_BLACK);

	
		
		
	organismMatrix->setOrganismInPosition(
		Vector2(organismMatrix->worldSize.x/2, organismMatrix->worldSize.y/2),
		new Human(this, Vector2(organismMatrix->worldSize.x / 2, organismMatrix->worldSize.y / 2))
	);

	for (int i = 0; i < 10; i++)
		while (true)
		{
			Vector2 tempVec = Vector2(rand() % organismMatrix->worldSize.x, rand() % organismMatrix->worldSize.y);
			if (!organismMatrix->getOrganismInPosition(tempVec)) {
				organismMatrix->setOrganismInPosition(tempVec, new Grass(this, tempVec));
				break;
			}
		}

	

	for (int i = 0; i < 1; i++)
		while (true)
		{
			Vector2 tempVec = Vector2(rand() % organismMatrix->worldSize.x, rand() % organismMatrix->worldSize.y);
			if (!organismMatrix->getOrganismInPosition(tempVec)) {
				organismMatrix->setOrganismInPosition(tempVec, new Wolf(this, tempVec));
				break;
			}
		}
	for (int i = 0; i < 10; i++)
		while (true)
		{
			Vector2 tempVec = Vector2(rand() % organismMatrix->worldSize.x, rand() % organismMatrix->worldSize.y);
			if (!organismMatrix->getOrganismInPosition(tempVec)) {
				organismMatrix->setOrganismInPosition(tempVec, new Sheep(this, tempVec));
				break;
			}
		}

	for (int i = 0; i < 3; i++)
		while (true)
		{
			Vector2 tempVec = Vector2(rand() % organismMatrix->worldSize.x, rand() % organismMatrix->worldSize.y);
			if (!organismMatrix->getOrganismInPosition(tempVec)) {
				organismMatrix->setOrganismInPosition(tempVec, new Antelope(this, tempVec));
				break;
			}
		}

	for (int i = 0; i < 5; i++)
		while (true)
		{
			Vector2 tempVec = Vector2(rand() % organismMatrix->worldSize.x, rand() % organismMatrix->worldSize.y);
			if (!organismMatrix->getOrganismInPosition(tempVec)) {
				organismMatrix->setOrganismInPosition(tempVec, new Fox(this, tempVec));
				break;
			}
		}

	for (int i = 0; i < 5; i++)
		while (true)
		{
			Vector2 tempVec = Vector2(rand() % organismMatrix->worldSize.x, rand() % organismMatrix->worldSize.y);
			if (!organismMatrix->getOrganismInPosition(tempVec)) {
				organismMatrix->setOrganismInPosition(tempVec, new Tortoise(this, tempVec));
				break;
			}
		}
	
	for (int i = 0; i < 4; i++)
		while (true)
		{
			Vector2 tempVec = Vector2(rand() % organismMatrix->worldSize.x, rand() % organismMatrix->worldSize.y);
			if (!organismMatrix->getOrganismInPosition(tempVec)) {
				organismMatrix->setOrganismInPosition(tempVec, new Belladona(this, tempVec));
				break;
			}
		}
		
	for (int i = 0; i < 2; i++)
		while (true)
		{
			Vector2 tempVec = Vector2(rand() % organismMatrix->worldSize.x, rand() % organismMatrix->worldSize.y);
			if (!organismMatrix->getOrganismInPosition(tempVec)) {
				organismMatrix->setOrganismInPosition(tempVec, new Guarana(this, tempVec));
				break;
			}
		}

	for (int i = 0; i < 3; i++)
		while (true)
		{
			Vector2 tempVec = Vector2(rand() % organismMatrix->worldSize.x, rand() % organismMatrix->worldSize.y);
			if (!organismMatrix->getOrganismInPosition(tempVec)) {
				organismMatrix->setOrganismInPosition(tempVec, new SawThistles(this, tempVec));
				break;
			}
		}

	render();
}