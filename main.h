// globals
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH (500)
#define SCREEN_HEIGHT (500)
#define ROWS 3
#define MATCH 3
#define SIZE (ROWS)*(ROWS)
#define CELLSIZE (int)((SCREEN_WIDTH)/(ROWS))
#define GRIDTHICKNESS 16
#define DEBUG

// globals

bool init();
void loop();
void handleMouse();

