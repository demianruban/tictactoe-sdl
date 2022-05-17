#include "placement.h"

extern SDL_Renderer* renderer;

Placement** createGrid();
void updateGrid(Placement* placements[]);
void mouseInputGrid(Placement* placements[], SDL_Point mousePos, bool pressed);
void renderGrid(Placement* placements[]);

