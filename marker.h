#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

typedef struct {
    int type;
    SDL_Texture* tex;
} Marker;

extern SDL_Renderer* renderer;

Marker* createMarker(int type);
void destroyMarker(Marker* marker);

