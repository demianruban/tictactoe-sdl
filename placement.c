#include <stdio.h>
#include <stdbool.h>

typedef struct Placement {
    SDL_Color hoverColor = 0xa0a0a0; // const
    float fadeSpeed = 0.1; // const
    bool fadeIn;
    bool markerPlaced;
    float alpha;
    SDL_Rect rect;
}

Placement* createPlacement(xIndex, yIndex, size)
{
    Placement* place = malloc(sizeof(Placement));
    place->hoverColor = 0xa0a0a0;
    place->fadeSpeed = 0.1;
    place->markerPlaced = false;
    place->alpha = 0;
    place->fadeSpeed = 0.1;
    place->rect->x = xIndex * size;
    place->rect->y = yIndex * size;
    place->rect->w = size;
    place->rect->h = size;

    return place;
}

void updatePlacement(Placement* place)
{
    if (place->fadeIn && alpha != 1) {
	alpha += fadeSpeed;
	if (alpha > 1)
	    alpha = 1;
    } else if (!fadeIn && alpha != 0) {
	alpha -= fadeSpeed;
	if (alpha < 0)
	    alpha = 0;
    }
}

void renderPlacement(SDL_Renderer *rend, Placement* place)
{
    SDL_RenderSetDrawColor(rend, place->hoverColor.r,
			place->hoverColor.g,
			place->hoverColor.b,
			(int)(alpha * 255));

    SDL_RenderFillRect(rend, place->x, place->y, place->width, place->height);
    SDL_RenderSetDrawColor(255, 255, 255, 255);
}

void hoverPlacement(Placement* place, SDL_Point* mousePos)
{
    if (SDL_HasIntersection(mousePos, place->rect)) {
	fadeIn = true;
    } else {
	fadeIn = false;
}

