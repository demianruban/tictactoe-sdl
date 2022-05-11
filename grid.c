#include "main.h"

#define GRIDTHICKNESS 16

void drwgrid(SDL_Renderer* rend)
{
    // set bg color
    SDL_SetRenderDrawColor(rend, 0x46, 0x46, 0x46, 0xFF);
    SDL_RenderClear(rend);

    SDL_SetRenderDrawColor(rend, 0x2E, 0x2E, 0x2E, 0xFF);

    int cellsize = WIDTH / ROWS;

    /* Correction of the original code with changing < operator to <=.
     * This addes the last lines to the screen, which was
     * handled by built-in Java function pack() in the original code.
     */
    for (int x = 0; x <= ROWS; x++) { // vertical lines
        SDL_Rect rowrect = {x * cellsize - (GRIDTHICKNESS / 2), 0, GRIDTHICKNESS, WIDTH};
        SDL_RenderFillRect(rend, &rowrect);
        for (int y = 0; y <= ROWS; y++) { // horizontal lines
            SDL_Rect colrect = {0, y * cellsize - (GRIDTHICKNESS / 2), WIDTH, GRIDTHICKNESS};
            SDL_RenderFillRect(rend, &colrect);
        }
    }

    SDL_RenderPresent(rend);
}

