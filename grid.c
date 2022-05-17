#include "main.h"
#include "grid.h"

Placement** createGrid()
{
    Placement** placements = malloc(sizeof(Placement) * SIZE);

    for (int i = 0; i < SIZE; i++) {
	int xIndex = i % ROWS;
	int yIndex = i / ROWS;
	placements[i] = createPlacement(xIndex, yIndex, CELLSIZE);
    }

    return placements;
}

void updateGrid(Placement* placements[])
{
    for (int i = 0; i < SIZE; i++)
	updatePlacement(placements[i]);
}

void mouseInputGrid(Placement* placements[], SDL_Point mousePos, int buttons)
{
    /* if ((buttons & SDL_BUTTON_LMASK) == 0) { */
    for (int i = 0; i < SIZE; i++)
	hoverPlacement(placements[i], mousePos);
    /* } else if ((buttons & SDL_BUTTON_LMASK) != 0) { */
	/* // place a marker */
    /* } */
}

void renderGrid(SDL_Renderer* rend, Placement* placements[])
{
    // set bg color
    SDL_SetRenderDrawColor(rend, 0x46, 0x46, 0x46, 0xFF);
    SDL_RenderClear(rend);

    SDL_SetRenderDrawColor(rend, 0x2E, 0x2E, 0x2E, 0xFF);


    /* drawing grid */
    /* TODO it's not symmetric */

    /* Correction of the original code with changing < operator to <=.
     * This adds the last lines to the screen, which was
     * handled by built-in Java function pack() in the original code.
     */
    for (int x = 0; x <= ROWS; x++) { // vertical lines
        SDL_Rect rowrect = {x * CELLSIZE - (GRIDTHICKNESS / 2), 0, GRIDTHICKNESS, SCREEN_WIDTH};
        SDL_RenderFillRect(rend, &rowrect);
        for (int y = 0; y <= ROWS; y++) { // horizontal lines
            SDL_Rect colrect = {0, y * CELLSIZE - (GRIDTHICKNESS / 2), SCREEN_WIDTH, GRIDTHICKNESS};
            SDL_RenderFillRect(rend, &colrect);
        }
    }

    // render placements with effects
    for (int i = 0; i < SIZE; i++)
	renderPlacement(rend, placements[i]);

}

