#include "params.h"

void render()
{
    SDL_BlitSurface(background_surface, NULL, screen_surface, NULL);
    SDL_UpdateWindowSurface(window);
}