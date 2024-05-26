#include "params.h"

void render()
{
    SDL_RenderClear(renderer);

    for (int i = 0; i < texture_storage.lenght; i++)
        SDL_RenderCopy(renderer, texture_storage.tx[i].texture, NULL, NULL);

    SDL_RenderPresent(renderer);
}