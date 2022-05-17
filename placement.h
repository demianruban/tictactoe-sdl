#include "marker.h"

typedef struct {
    SDL_Color hoverColor; // const
    float fadeSpeed; // const
    bool markerPlaced;
    bool fadeIn;
    float alpha;
    SDL_Rect* rect;
    Marker* marker;
} Placement;

extern int markerCound;
extern SDL_Renderer* renderer;

Placement* createPlacement(int xIndex, int yIndex, int size);
void updatePlacement(Placement* place);
void renderPlacement(Placement* place);
void hoverPlacement(Placement* place, SDL_Point mousePos);
void clickPlacement(Placement* place, SDL_Point mousePos);

