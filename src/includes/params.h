#include <SDL2/SDL.h>

#ifndef PARAMS_H
#define PARAMS_H

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

struct texture
{
    SDL_Texture *texture;
    int width;
    int height;
};

typedef struct
{
    struct texture *tx;
    int lenght;
} Texture_storage;

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern Texture_storage texture_storage;

#endif