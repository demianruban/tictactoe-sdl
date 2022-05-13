#include "placement.h"
typedef struct {
    Placement* placements[SIZE];
    int size;
    int thickness;
} Grid;

Grid* createGrid(Placements* placements, Grid* grid);
void renderGrid(SDL_Renderer* rend);

