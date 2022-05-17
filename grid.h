#include "placement.h"

extern SDL_Renderer* renderer;

Placement** createGrid();
void updateGrid(Placement* placements[]);
void mouseMoveGrid(Placement* placements[], SDL_Point mousePos);
void mouseClickGrid(Placement* placements[], SDL_Point mousePos);
void renderGrid(Placement* placements[]);

