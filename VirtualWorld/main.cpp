#include "curses.h"
#include "World.h"
#include "utils/Vector2.cpp"

int main()
{
	initscr();
	new World(Vector2(50,50));
	endwin();

	return 0;
}