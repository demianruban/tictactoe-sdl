#include "main.h"

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

SDL_Window* win;
SDL_Renderer* rend;

// SDL_Rect* cells[9]; // TODO make intuitive collision handler

int main(void) {

    if (!init()) {
	printf("Couldn't initialize!");
	return 1;
    } else {
	drwgrid(rend);

	loop();

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
				WIDTH, HEIGHT, 0);

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

        // get cursor position relative to window
        int mouse_x, mouse_y;
        int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

	// check if mouse in central rect
        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
	    if (mouse_x > 214 && mouse_x < 428 && mouse_y > 160 && mouse_y < 320)
		SDL_Log("You pressed the cell in the middle!\n");
	}

	SDL_Delay(1000/5);
    }
}

