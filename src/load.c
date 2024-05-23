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

    int imgFlags = IMG_INIT_PNG;

    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }

    screen_surface = SDL_GetWindowSurface(window);

    if (screen_surface == NULL)
    {
        printf("SDL_GetWindowSurface Error: %s\n", IMG_GetError());
        return 1;
    }

    int is_meedia_load = !load_media();

    if (!is_meedia_load)
        return 1;

    return 0;
}

int load_media()
{
    int is_surface_loaded = !load_surface(&background_surface, "media/loaded.png");

    if (!is_surface_loaded)
    {
        printf("Failed to load PNG image!\n");
        return 1;
    }

    return 0;
}

void free_sdl_resources()
{
    SDL_FreeSurface(background_surface);
    background_surface = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    IMG_Quit();
    SDL_Quit();
}

int load_surface(SDL_Surface **frame_surface, char *path)
{
    SDL_Surface *loaded_surface = IMG_Load(path);

    if (loaded_surface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
        return 1;
    }

    *frame_surface = SDL_ConvertSurface(loaded_surface, screen_surface->format, 0);

    if (frame_surface == NULL)
    {
        printf("Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError());
        return 1;
    }

    SDL_FreeSurface(loaded_surface);

    return 0;
}
