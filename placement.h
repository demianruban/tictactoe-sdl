typedef struct {
    SDL_Color hoverColor; // const
    float fadeSpeed; // const
    bool markerPlaced;
    bool fadeIn;
    float alpha;
    SDL_Rect* rect;
} Placement;

Placement* createPlacement(int xIndex, int yIndex, int size);
void updatePlacement(Placement* place);
void renderPlacement(SDL_Renderer *rend, Placement* place);
void hoverPlacement(Placement* place, SDL_Point mousePos);

