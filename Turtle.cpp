#include "Turtle.h"
#include <iostream>
#include  <math.h>

SDL_Point* Turtle::GetPoints(){
	return &points[0];
}

int Turtle::GetPointsCount(){
	return points.size();
}

void Turtle::AddPoint(int x, int y){
	SDL_Point point;
	point.x = x;
	point.y = y;
	points.push_back(point);
	currentPoint = point;
}

Turtle::Turtle(int x, int y){
	AddPoint(x, y);
}

void Turtle::Forward(int length){
	int b = currentPoint.y - (tan(-a * M_PI / 180) * currentPoint.x);

	int newX;
	int newY;
	float modifier = 0.005;
	do{
		if (a == 0){
			newX = currentPoint.x + modifier;
			newY = currentPoint.y;
		}
		else if (a == 90){
			newX = currentPoint.x;
			newY = currentPoint.y - modifier;
		}
		else if (a == 180{
			newX = currentPoint.x - modifier;
			newY = currentPoint.y;
		}
		else if (a == 270){
			newX = currentPoint.x;
			newY = currentPoint.y + modifier;
		}
		else if (a > 0 && a < 90){
			newX = currentPoint.x + modifier;
			newY = (tan(-a * M_PI / 180) * newX) + b;
		}
		else if (a > 90 && a < 180){
			newX = currentPoint.x - modifier;
			newY = (tan(-a * M_PI / 180) * newX) + b;
		}
		else if (a > 270 && a < 360){
			newX = currentPoint.x + modifier;
			newY = (tan(-a * M_PI / 180) * newX) + b;
		}
		else{
			newX = currentPoint.x - modifier;
			newY = (tan(-a * M_PI / 180) * newX) + b;
		}
		modifier += 0.0005;
	} while (sqrt((pow(newX - currentPoint.x, 2) + pow(newY - currentPoint.y, 2))) - length < 0.0005);
	AddPoint(newX, newY);
}

void Turtle::Left(int angle){
	a += angle;
	a %= 360;
}

void Turtle::Right(int angle){
	a -= angle;
	a %= 360;
}
