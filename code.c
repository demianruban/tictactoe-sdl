#include "code.h"

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)

SDL_Window* win;
SDL_Renderer* rend;

void render_field(SDL_Renderer* rend) {
    // make screen white
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    SDL_RenderClear(rend);

    // procedurically create tictactoe field
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

    SDL_RenderDrawLine(rend, 214, 10, 214, 470);
    SDL_RenderDrawLine(rend, 428, 10, 428, 470);
    SDL_RenderDrawLine(rend, 10,  160, 630, 160);
    SDL_RenderDrawLine(rend, 10,  320, 630, 320);

    SDL_RenderPresent(rend);
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
				WINDOW_WIDTH, WINDOW_HEIGHT, 0);

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
    bool close = false;
    while (!close) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
	    if (event.type == SDL_QUIT)
		return;
	}

        // get cursor position relative to window
        int mouse_x, mouse_y;
        int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

	// check if mouse in central rect
	if (mouse_x > 214 && mouse_x < 428 && mouse_y > 160 && mouse_y < 320) {
	    SDL_Log("Collision!\n");
	}

	SDL_Delay(1000/5);
    }
}

int main(void) {

    if (!init()) {
	printf("Couldn't initialize!");
	return 1;
    } else {
	render_field(rend);

	loop();

	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
    }
}

