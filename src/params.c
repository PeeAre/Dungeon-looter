#include <SDL2/SDL.h>
#include "params.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// The window we'll be rendering to
SDL_Window *window = NULL;

// The window renderer
SDL_Renderer *renderer = NULL;

Texture_storage texture_storage = {.tx = NULL, .lenght = 0};