#pragma once

#include <vector>
#include "SDL.h"
#include <math.h>

class Turtle{
	int a = 0;
	SDL_Point currentPoint;
	std::vector<SDL_Point> points;
	void AddPoint(int x, int y);
public:
	Turtle(int x, int y);
	SDL_Point* GetPoints();
	int GetPointsCount();
	void Forward(int length);
	void Left(int angle);
	void Right(int angle);
};

