#include "main.h"
#include "grid.h"

static const int thickness = 16;

Grid* createGrid()
{
    Grid* grid = malloc(sizeof(Grid));

    // calloc(size, ptr) == malloc(size * ptr)
    *grid = (Grid){CELLSIZE, thickness, {calloc(SIZE, sizeof(Placement))}};

    for (int i = 0; i < SIZE; i++) {
	int xIndex = i % ROWS;
	int yIndex = i / ROWS;
	grid->placements[i] = createPlacement(xIndex, yIndex, CELLSIZE);
    }

    return grid;
}

void updateGrid(Grid* grid)
{
    for (int i = 0; i < SIZE; i++)
	updatePlacement(grid->placements[i]);
}

void mouseInputGrid(Grid* grid, SDL_Point mousePos, int buttons)
{
    /* if ((buttons & SDL_BUTTON_LMASK) == 0) { */
    for (int i = 0; i < SIZE; i++)
	hoverPlacement(grid->placements[i], mousePos);
    /* } else if ((buttons & SDL_BUTTON_LMASK) != 0) { */
	/* // place a marker */
    /* } */
}

void renderGrid(SDL_Renderer* rend, Grid* grid)
{
    // set bg color
    SDL_SetRenderDrawColor(rend, 0x46, 0x46, 0x46, 0xFF);
    SDL_RenderClear(rend);

    SDL_SetRenderDrawColor(rend, 0x2E, 0x2E, 0x2E, 0xFF);

    /* Correction of the original code with changing < operator to <=.
     * This adds the last lines to the screen, which was
     * handled by built-in Java function pack() in the original code.
     */

    // TODO it's not symmetric
    for (int x = 0; x <= ROWS; x++) { // vertical lines
        SDL_Rect rowrect = {x * CELLSIZE - (thickness / 2), 0, thickness, SCREEN_WIDTH};
        SDL_RenderFillRect(rend, &rowrect);
        for (int y = 0; y <= ROWS; y++) { // horizontal lines
            SDL_Rect colrect = {0, y * CELLSIZE - (thickness / 2), SCREEN_WIDTH, thickness};
            SDL_RenderFillRect(rend, &colrect);
        }
    }

    // render placements with effects
    for (int i = 0; i < SIZE; i++)
	renderPlacement(rend, grid->placements[i]);

    SDL_RenderPresent(rend);
}

