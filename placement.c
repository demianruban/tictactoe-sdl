#include <SDL_render.h>
#include <SDL_mouse.h>
#include "placement.h"
#include "main.h"

#if defined(DEBUG)
#include <SDL_log.h>
#endif

extern int markerCount;
extern SDL_Renderer* renderer;

Placement* createPlacement(int xIndex, int yIndex, int size)
{
    // all structs must be allocated!
    Placement* place = malloc(sizeof(Placement));
    *place = (Placement){
		.fadeSpeed=0.1,
		.markerPlaced=false,
		.fadeIn=false,
		.alpha=0,
		.rect=malloc(sizeof(SDL_Rect)),
		.marker=malloc(sizeof(Marker))
		};

    place->rect->x = xIndex * size;
    place->rect->y = yIndex * size;
    place->rect->w = size;
    place->rect->h = size;

    place->marker = NULL;

#ifdef DEBUG
    SDL_Log("placement rect: %d %d %d %d", place->rect->x, place->rect->y, place->rect->w, place->rect->h);
#endif

    return place;
}

void updatePlacement(Placement* place)
{
    // value of alpha reverts itself if it's
    // equal to 255 so make sure don't touch the
    // borders of it (8 byte integer)
    if (!place->marker) { // no marker placed
	if (place->fadeIn && place->alpha < 0.9) {
	    place->alpha += 0.1;
	} else if (!place->fadeIn && place->alpha > 0.1) {
	    place->alpha -= 0.1;
	}
    }
}

void renderPlacement(Placement* place)
{
    if (!place->marker) { // if no marker set
	SDL_SetRenderDrawColor(renderer, 160, 160, 160,
			    (int)(place->alpha * 255));

	SDL_RenderFillRect(renderer, place->rect);
    } else { // if there is a marker
	SDL_RenderCopy(renderer, place->marker->tex, NULL, place->rect);
    }
}

void hoverPlacement(Placement* place, SDL_Point mousePos)
{
    if (SDL_PointInRect(&mousePos, place->rect)) {
	place->fadeIn = true;
    } else {
	place->fadeIn = false;
    }
}

void clickPlacement(Placement* place, SDL_Point mousePos)
{
    if (SDL_PointInRect(&mousePos, place->rect) && !place->marker) {
	if (markerCount < SIZE) {
	    place->marker = createMarker(markerCount);
	    markerCount++;
	} else {
	    // TODO end game block
	}
    }
}

void destroyPlacement(Placement* place)
{
    destroyMarker(place->marker);
    free(place->rect);
    free(place);
}

