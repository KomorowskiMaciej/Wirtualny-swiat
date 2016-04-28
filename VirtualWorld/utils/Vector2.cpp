#pragma once

struct Vector2
{
	Vector2() {
		x = 0;
		y = 0;
	}

	Vector2(int l_x, int l_y) {
		x = l_x;
		y = l_y;
	}

	int x, y;
};