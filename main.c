#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "main.h"
#include "grid.h"

SDL_Window* win;
SDL_Renderer* renderer;

SDL_Point mousePos;
Placement** grid;

int markerCount = 0;

int main(void) {

    if (!init()) {
	printf("Couldn't initialize!");
	return 1;
    } else {

	grid = createGrid();

	loop();

	// TODO add efficient memory freeing
	SDL_DestroyRenderer(renderer);
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

	    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	    if (!renderer)
	    {
	      printf("error creating renderer: %s\n", SDL_GetError());
	      success = false;
	    }

	    // this enables alpha blending functionality
	    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	}
    }

    return success;
}

void loop() {
    while (1) {

	SDL_GetMouseState(&mousePos.x, &mousePos.y);

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
	    switch (event.type) {
		case SDL_QUIT:
		    return;
		case SDL_MOUSEMOTION:
		    mouseMoveGrid(grid, mousePos);
		    break;
		case SDL_MOUSEBUTTONUP:
		    mouseClickGrid(grid, mousePos);
		    break;
	    }

	}

	updateGrid(grid);
	renderGrid(grid);

	/* it's separate for not calling it multiple times */
	SDL_RenderPresent(renderer);

	SDL_Delay(1000/60);
    }
}

