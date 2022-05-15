#include <stdbool.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include "placement.h"

Placement* createPlacement(int xIndex, int yIndex, int size)
{
    Placement* place = malloc(sizeof(Placement));
    place->hoverColor = (SDL_Color){0x0A, 0x0A, 0x0A, 0xFF};
    place->fadeSpeed = 0.1;
    place->markerPlaced = false;
    place->fadeIn = false;
    place->alpha = 0;
    place->rect->x = xIndex * size;
    place->rect->y = yIndex * size;
    place->rect->w = size;
    place->rect->h = size;

    return place;
}

void updatePlacement(Placement* place)
{
    if (place->fadeIn && place->alpha != 1) {
	place->alpha += place->fadeSpeed;
	if (place->alpha > 1)
	    place->alpha = 1;
    } else if (!place->fadeIn && place->alpha != 0) {
	place->alpha -= place->fadeSpeed;
	if (place->alpha < 0)
	    place->alpha = 0;
    }
}

void renderPlacement(SDL_Renderer *rend, Placement* place)
{
    SDL_SetRenderDrawColor(rend, place->hoverColor.r,
			place->hoverColor.g,
			place->hoverColor.b,
			(int)(place->alpha * 255));

    SDL_RenderFillRect(rend, place->rect);
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
}

void hoverPlacement(Placement* place, SDL_Point mousePos)
{
    if (SDL_PointInRect(&mousePos, place->rect)) {
	place->fadeIn = true;
    } else {
	place->fadeIn = false;
    }
}

