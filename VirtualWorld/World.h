#pragma once
#include "curses.h"
#include "Organisms/Organisms.h"
#include "utils/Vector2.cpp"
#include "curses.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Organisms/OrganismMatrix.h"

using namespace std;

class World
{
private:
	void update();
	void render();
	void loop();
	void prepare();
	Vector2 humanMovePosition;
	std::string humanMovePositionComment;
	string events;
	OrganismMatrix *organismMatrix;
	void SetWindow(int Width, int Height)
	{
		_COORD coord;
		coord.X = Width;
		coord.Y = Height;

		_SMALL_RECT Rect;
		Rect.Top = 0;
		Rect.Left = 0;
		Rect.Bottom = Height - 1;
		Rect.Right = Width - 1;

		HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
		SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
		SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
	}

public:
	Vector2 getHumanMovePosition();
	std::string getMovePositionComment();
	void setHumanMovePosition(Vector2 vec2);
	void setMovePositionComment(std::string comment);
	void addEvent(string _event);
	OrganismMatrix* getOrganismMatrix();
	World(Vector2 l_mapSize) {
		events = "";
		humanMovePositionComment = "";
		SetWindow(l_mapSize.y+10, l_mapSize.x + 20);
		organismMatrix = new OrganismMatrix(l_mapSize);
		humanMovePosition = Vector2(0,0);
		prepare();
		loop();
	}
};