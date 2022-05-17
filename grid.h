#include "placement.h"

Placement** createGrid();
void updateGrid(Placement* placements[]);
void mouseInputGrid(Placement* placements[], SDL_Point mousePos, int buttons);
void renderGrid(SDL_Renderer* rend, Placement* placements[]);

