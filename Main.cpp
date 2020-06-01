#include "SDL.h"
#include "turtle.h"
#include <iostream>
void Sierpinski(Turtle& turtle, int minBok, int bok){
	if (bok < minBok)
		return;
	for (int i = 0; i < 3; i++) {
		turtle.Forward(bok);
		turtle.Left(120);
		Sierpinski(turtle, minBok, bok / 2);
	}
}
bool KrzywaKocha(Turtle& turtle, int minBok, int bok)
{
	if (bok < minBok)
	{
		return false;
	}

	if (!KrzywaKocha(turtle, minBok, bok / 3))
	{
		turtle.Forward(bok);
	}
	turtle.Left(60);
	if (!KrzywaKocha(turtle, minBok, bok / 3))
	{
		turtle.Forward(bok);
	}
	turtle.Right(120);
	if (!KrzywaKocha(turtle, minBok, bok / 3))
	{
		turtle.Forward(bok);
	}
	turtle.Left(60);
	if (!KrzywaKocha(turtle, minBok, bok / 3))
	{
		turtle.Forward(bok);
	}
	return true;
}

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = SDL_CreateWindow("zolw", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;
	bool play = true;
	Turtle turtle(250, 250);
	KrzywaKocha(turtle, 27, 243);
	while (play){
		SDL_SetRenderDrawColor(renderer, 125, 125, 125, 125);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderDrawLines(renderer, turtle.GetPoints(), turtle.GetPointsCount());
		SDL_RenderPresent(renderer);
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				play = false;
			}
		}
		SDL_Delay(500);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0;
}