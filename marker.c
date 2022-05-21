#include "marker.h"
#include <SDL2/SDL_render.h>

extern SDL_Renderer* renderer;

Marker* createMarker(int type)
{
    Marker* marker = malloc(sizeof(Marker));

    SDL_Surface* surface;

    marker->type = type % 2;

    // 1 == x and 0 == o
    if (marker->type) {
	surface = IMG_Load("res/x.png");
    } else {
	surface = IMG_Load("res/o.png");
    }

    if (!surface)
        printf("error creating surface: %s\n", SDL_GetError());

    marker->tex = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);
    if (!marker->tex)
        printf("error creating texture: %s\n", SDL_GetError());

    return marker;
}

void destroyMarker(Marker* marker)
{
    free(marker->tex);
    free(marker);
}

