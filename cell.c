#include "main.h"
#include <SDL_image.h>

struct Marker {
    int type;
    int (*render)(SDL_Renderer* rend);
}

void drwmarker(SDL_Renderer* rend, int type)
{
    SDL_Rect dest;

    SDL_Surface* surface = IMG_Load("res/o.png");
    if (!surface)
    {
        printf("error creating surface\n");
        SDL_Quit();
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
    if (!tex)
    {
        printf("error creating texture: %s\n", SDL_GetError());
        SDL_Quit();
    }
    SDL_FreeSurface(surface);
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

    dest.w /= 3;
    dest.h /= 3;

    printf("calc: %d\n", SCREEN_WIDTH/dest.h);

    dest.x = 0;
    dest.y = 0;

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex, NULL, &dest);
    SDL_RenderPresent(rend);
}

