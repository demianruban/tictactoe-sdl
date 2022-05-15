#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "main.h"
#include "grid.h"

SDL_Window* win;
SDL_Renderer* rend;

SDL_Point mousePos;
Grid* grid;

int main(void) {

    if (!init()) {
	printf("Couldn't initialize!");
	return 1;
    } else {

	grid = createGrid();

	//loop();
	printf("initialized!");

	// TODO add efficient memory freeing
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
    }
}

bool init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
    {
	printf("error initializing SDL: %s\n", SDL_GetError());
	return 1;
    } else {

	win = SDL_CreateWindow("TicTacToe",
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (!win)
	{
	    printf("error creating window: %s\n", SDL_GetError());
	    SDL_Quit();
	    success = false;
	} else {

	    rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	    if (!rend)
	    {
	      printf("error creating renderer: %s\n", SDL_GetError());
	      success = false;
	    }
	}
    }

    return success;
}

void loop() {
    while (1) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
	    if (event.type == SDL_QUIT)
		return;
	}

	handleMouse();
	updateGrid(grid);
	renderGrid(rend, grid);

	SDL_Delay(1000/5);
    }
}

void handleMouse()
{
    int buttons = SDL_GetMouseState(&mousePos.x, &mousePos.y);

    if (buttons) {
	mouseInputGrid(grid, mousePos);
    }
}

