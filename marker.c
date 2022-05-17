#include "marker.h"

void createMarker(SDL_Renderer* rend, int type)
{
    Marker* marker = malloc(sizeof(Marker));
    *marker = (Marker){
	    x, y,
	    type % 2,
	    malloc(sizeof(SDL_Texture)),
	    malloc(sizeof(SDL_Rect
	    };

    marker->type = type % 2;

    // 1 == x, 0 == o
    if (type)
	SDL_Surface* surface = IMG_Load("res/x.png");
    else
	SDL_Surface* surface = IMG_Load("res/o.png");

    if (!surface)
        printf("error creating surface: %s\n", SDL_GetError());

    marker->tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!tex)
        printf("error creating texture: %s\n", SDL_GetError());

    return marker;
}

void renderMarker(SDL_Render* rend, Marker* marker, x, y)
{
    SDL_RenderCopy(rend, marker->tex, NULL, NULL);
}

