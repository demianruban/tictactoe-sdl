#include "main.h"
#include "grid.h"

extern SDL_Renderer* renderer;
extern int markerCount;

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

void mouseMoveGrid(Placement* placements[], SDL_Point mousePos)
{
    for (int i = 0; i < SIZE; i++)
	hoverPlacement(placements[i], mousePos);
}
void mouseClickGrid(Placement* placements[], SDL_Point mousePos)
{
    for (int i = 0; i < SIZE; i++)

	if (SDL_PointInRect(&mousePos, placements[i]->rect) &&
		!placements[i]->marker) {


	    placements[i]->marker = createMarker(markerCount);
	    markerCount++;

	    Marker** matchLine = checkWin(placements);

	    if (matchLine != NULL) {
		SDL_Log("%s WON!", matchLine[0]->type ? "X" : "O");
	    } else if (markerCount >= SIZE) {
		SDL_Log("TIE!");
	    }
	}
}

void renderGrid(Placement* placements[])
{
    // set bg color
    SDL_SetRenderDrawColor(renderer, 0x46, 0x46, 0x46, 0xFF);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0x2E, 0x2E, 0x2E, 0xFF);


    /* drawing grid */
    /* TODO it's not symmetric */
    for (int x = 0; x <= ROWS; x++) { // vertical lines
        SDL_Rect rowrect = {x * CELLSIZE - (GRIDTHICKNESS / 2), 0, GRIDTHICKNESS, SCREEN_WIDTH};
        SDL_RenderFillRect(renderer, &rowrect);
        for (int y = 0; y <= ROWS; y++) { // horizontal lines
            SDL_Rect colrect = {0, y * CELLSIZE - (GRIDTHICKNESS / 2), SCREEN_WIDTH, GRIDTHICKNESS};
            SDL_RenderFillRect(renderer, &colrect);
        }
    }

    // rendererer placements with effects
    for (int i = 0; i < SIZE; i++)
	renderPlacement(placements[i]);

}

void resetGrid(Placement* placements[])
{
    for (int i = 0; i < SIZE; i++ )
	placements[i]->marker = NULL;

    // TODO winning variables
    /* gameEnd = false; */
    /* winType = -1; */
}

void destroyGrid(Placement** placements)
{
    /* for (int i = 0; i < SIZE; i++) */
	/* destroyPlacement(placements[i]); */
    free(placements);
}

