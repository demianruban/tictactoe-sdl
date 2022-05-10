#include "code.h"

#include <stdio.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)

int main(void) {
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
    {
	printf("error initializing SDL: %s\n", SDL_GetError());
	return 1;
    }

    SDL_Window* win = SDL_CreateWindow("TicTacToe",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if (!win)
    {
        printf("error creating window: %s\n", SDL_GetError());
        SDL_Quit();
	    return 1;
    }

    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

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

    if (!rend)
    {
      printf("error creating renderer: %s\n", SDL_GetError());
      SDL_DestroyWindow(win);
      SDL_Quit();
      return 1;
    }


    SDL_Delay(5000);

    SDL_Quit();
    return 0;
}

