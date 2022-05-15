#include "placement.h"

typedef struct {
    int size;
    int thickness;
    Placement* placements[SIZE];
} Grid;

Grid* createGrid();
void updateGrid(Grid* grid);
void mouseInputGrid(Grid* grid, SDL_Point mousePos);
void renderGrid(SDL_Renderer* rend, Grid* grid);

