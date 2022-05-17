#include <SDL_render.h>
#include <stdbool.h>

#define SCREEN_WIDTH (500)
#define SCREEN_HEIGHT (500)
#define ROWS 3
#define MATCH 3
#define SIZE (ROWS)*(ROWS)
#define CELLSIZE (int)((SCREEN_WIDTH)/(ROWS))
#define GRIDTHICKNESS 16
#define DEBUG

bool init();
void loop();
void handleMouse();

