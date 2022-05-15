#include <SDL_render.h>
#include <stdbool.h>

#define SCREEN_WIDTH (500)
#define SCREEN_HEIGHT (500)
#define ROWS 3
#define MATCH 3
#define SIZE (ROWS)*(ROWS)

bool init();
void loop();
void handleMouse();

