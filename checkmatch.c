#include <stdio.h>

void checkWin(int markers[][])
{
    int type = -1;
    int checkCount = 0;

    for (int i = 0; i < SIZE; i++) {
	int x = i % ROWS;
	int y = i / ROWS;

	// diagonal check from bottom left to top right
	checkMatch(markers, x, y, 1, -1);
    }
    return match;
}

Marker** checkMatch(int markers[][], int x, int y, int dX, int dY, int index)
{
    // 1 == x, 0 == o
    for (int i = 0; i < SIZE
    while (x >= 0 && x <= MATCH && y >= 0 && y <= MATCH) {
	marker = markers[x][y];

	x += dX;
	x += dY;
    }

    return NULL;
}

