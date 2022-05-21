#include <stdio.h>
#include "checkmatch.h"
#include "main.h"

Marker** checkWin(Placement* placements[])
{
    Marker** matchLine = NULL; // marker array to hightlight the match

    for (int i = 0; i < SIZE; i++) {
	int x = i % ROWS;
	int y = i / ROWS;

	// horizontal check from left ro right
	if (x <= ROWS - MATCH) {
	    SDL_Log("horizontal check");
	    matchLine = checkMatch(placements, x, y, 0, 1);
	}

	// vertical check
	if (matchLine == NULL) {// if match line is still not found
	    if (y <= ROWS - MATCH) {
		SDL_Log("vertical check");
		matchLine = checkMatch(placements, x, y, 1, 0);
	    }
	}

	// bottom left to top right
	if (matchLine == NULL) {
	    if (y >= MATCH - 1 && x <= ROWS - MATCH) {// checks to not access memory out of bound
		SDL_Log("bottom left to top right check");
		matchLine = checkMatch(placements, x, y, 1, -1);
	    }
	}

	// top left to bottom right
	if (matchLine == NULL) {
	    if (x <= ROWS - MATCH && y <= ROWS - MATCH) {// checks to not access memory out of bound
		SDL_Log("top left to bottom right check");
		matchLine = checkMatch(placements, x, y, 1, 1);
	    }
	}

	if (matchLine != NULL) {
	    for (int i = 0; i < (sizeof(matchLine) / sizeof(Marker*)); i++)
		SDL_Log("Marker ptr: %p\n", matchLine[i]);
	    return matchLine;
	}
    }
    return NULL;
}

Marker** checkMatch(Placement* placements[], int x, int y, int dX, int dY)
{
    Marker* matchLine[SIZE];
    int index = 0; // index for matchLine arr
    // 1 == x, 0 == o
    int type = -1;
    int checkCount = 0;

    /* while (checkCount <= MATCH) { */
    for (int i = 0; i <= MATCH; i++) {
	bool found = false;
	Marker* marker = placements[x * ROWS + y]->marker; //convert 2d indexes to 1d

	if (marker != NULL) {
	    if (type == -1)
		type = marker->type;

	    if (marker->type == type) {
		matchLine[index] = marker;
		index++;
		found = true;
	    }
	}
	if (!found && (sizeof(matchLine) / sizeof(Marker*)) < MATCH) {
	    memset(matchLine, 0, SIZE);
	    type = -1;
	}

	x += dX;
	y += dY;
    }

    SDL_Log("sizeof matchLine: %lu", (sizeof(matchLine) / sizeof(Marker*)));
    return (sizeof(matchLine) / sizeof(Marker*)) >= MATCH ? matchLine : NULL;
}

