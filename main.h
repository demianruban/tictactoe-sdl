#include <SDL_render.h>
#include <stdbool.h>

#define WIDTH (500)
#define HEIGHT (500)
#define ROWS 3
#define MATCH 3
#define SIZE (ROWS)*(ROWS)

void drwgrid(SDL_Renderer* rend);
bool init();
void loop();
void drwmarker(SDL_Renderer* rend, int type);

