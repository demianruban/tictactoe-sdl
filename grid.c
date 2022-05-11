#include "main.h"

#define GRIDTHICKNESS 16

void drwgrid(SDL_Renderer* rend, SDL_Window* win)
{
    SDL_SetRenderDrawColor(rend, 0x46, 0x46, 0x46, 0xFF);
    SDL_RenderClear(rend);
    SDL_SetRenderDrawColor(rend, 0x2E, 0x2E, 0x2E, 0xFF);

    int cellsize = WIDTH / ROWS;

    /* Original implementation with pack() function in main */
    for (int x = 0; x <= ROWS; x++) { // horizontal lines
        SDL_Rect rowrect = {x * cellsize - (GRIDTHICKNESS / 2), 0, GRIDTHICKNESS, WIDTH};
        SDL_RenderFillRect(rend, &rowrect);
        for (int y = 0; y <= ROWS; y++) { // vertical lines
            SDL_Rect colrect = {0, y * cellsize - (GRIDTHICKNESS / 2), WIDTH, GRIDTHICKNESS};
            SDL_RenderFillRect(rend, &colrect);
        }
    }

    SDL_RenderPresent(rend);

}

