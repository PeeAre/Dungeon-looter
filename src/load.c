#include <SDL2/SDL_image.h>
#include "load.h"
#include "params.h"

int init()
{
    int is_sdl_init = SDL_Init(SDL_INIT_VIDEO);

    if (is_sdl_init < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());

        return 1;
    }

    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());

        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());

        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());

        return 1;
    }

    int is_meedia_load = !load_media();

    if (!is_meedia_load)
        return 1;

    return 0;
}

int load_media()
{
    int is_texture_loaded = !load_texture("media/loaded.png");

    if (!is_texture_loaded)
    {
        printf("Failed to load PNG image!\n");

        return 1;
    }

    return 0;
}

int load_texture(char *path)
{
    texture_storage.tx = realloc(texture_storage.tx, sizeof(struct texture) * ++texture_storage.lenght);
    texture_storage.tx[texture_storage.lenght - 1].texture = IMG_LoadTexture(renderer, path);
    SDL_QueryTexture(texture_storage.tx->texture, NULL, NULL, &texture_storage.tx->width, &texture_storage.tx->height);

    if (texture_storage.tx == NULL)
    {
        printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());

        return 1;
    }

    return 0;
}

void free_sdl_resources()
{
    for (int i = 0; i < texture_storage.lenght; i++)
    {
        SDL_DestroyTexture(texture_storage.tx[i].texture);
        texture_storage.tx->texture = NULL;
    }

    free(texture_storage.tx);

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    IMG_Quit();
    SDL_Quit();
}