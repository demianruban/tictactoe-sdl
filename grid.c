#include "main.h"
#include "grid.h"

Grid* createGrid()
{
    Grid* grid = malloc(sizeof(Grid));

    int size = SCREEN_WIDTH / ROWS;
    int thickness = 16;

    // calloc(size, ptr) == malloc(size * ptr)
    *grid = (Grid){size, thickness, {calloc(SIZE, sizeof(Placement))}};

    for (int i = 0; i < SIZE; i++) {
	int xIndex = i % ROWS;
	int yIndex = i / ROWS;
	grid->placements[i] = createPlacement(xIndex, yIndex, size);
    }

    return grid;
}

void updateGrid(Grid* grid)
{
    for (int i = 0; i < SIZE; i++)
	updatePlacement(grid->placements[i]);
}

void mouseInputGrid(Grid* grid, SDL_Point mousePos)
{
    for (int i = 0; i < SIZE; i++)
	hoverPlacement(grid->placements[i], mousePos);
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
        SDL_Rect rowrect = {x * grid->size - (grid->thickness / 2), 0, grid->thickness, SCREEN_WIDTH};
        SDL_RenderFillRect(rend, &rowrect);
        for (int y = 0; y <= ROWS; y++) { // horizontal lines
            SDL_Rect colrect = {0, y * grid->size - (grid->thickness / 2), SCREEN_WIDTH, grid->thickness};
            SDL_RenderFillRect(rend, &colrect);
        }
    }

    // render placements with effects
    for (int i = 0; i < SIZE; i++)
	renderPlacement(rend, grid->placements[i]);

    SDL_RenderPresent(rend);
}

