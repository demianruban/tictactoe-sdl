#include "marker.h"
#include <SDL2/SDL_render.h>

extern SDL_Renderer* renderer;

Marker* createMarker(int type)
{
    Marker* marker = malloc(sizeof(Marker));

    marker->type = type % 2;

    SDL_Surface* surface;

    // 1 == x, 0 == o
    if (type) {
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

