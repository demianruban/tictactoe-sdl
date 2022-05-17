#include <stdbool.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include "placement.h"
#include "main.h"

#if defined(DEBUG)
#include <SDL_log.h>
#endif

Placement* createPlacement(int xIndex, int yIndex, int size)
{
    // all structs must be allocated!
    Placement* place = malloc(sizeof(Placement));
    *place = (Placement){
		.fadeSpeed=0.1,
		.markerPlaced=false,
		.fadeIn=false,
		.alpha=0,
		.rect=malloc(sizeof(SDL_Rect))
		};

    place->rect->x = xIndex * size;
    place->rect->y = yIndex * size;
    place->rect->w = size;
    place->rect->h = size;

#if defined(DEBUG)
    SDL_Log("placement rect: %d %d %d %d", place->rect->x, place->rect->y, place->rect->w, place->rect->h);
#endif

    return place;
}

void updatePlacement(Placement* place)
{
    // value of alpha reverts itself if it's
    // equal to 255 so make sure don't touch the
    // borders of it (8 byte integer)
    if (!place->markerPlaced) {
	if (place->fadeIn && place->alpha < 0.9) {
	    place->alpha += 0.1;
	} else if (!place->fadeIn && place->alpha > 0.1) {
	    place->alpha -= 0.1;
	}
    }
}

void renderPlacement(SDL_Renderer *rend, Placement* place)
{
    SDL_SetRenderDrawColor(rend, 160, 160, 160,
			(int)(place->alpha * 255));

    SDL_RenderFillRect(rend, place->rect);
}

void hoverPlacement(Placement* place, SDL_Point mousePos)
{
    if (SDL_PointInRect(&mousePos, place->rect)) {
	place->fadeIn = true;
    } else {
	place->fadeIn = false;
    }
}

void setPlacement(Placement* place, bool isSet)
{
    place->markerPlaced = isSet;

    if(isSet)
	place->fadeIn = false;
}

