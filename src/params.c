#include <SDL2/SDL.h>
#include "params.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// The window we'll be rendering to
SDL_Window *window = NULL;

// The surface contained by the window
SDL_Surface *screen_surface = NULL;

// Current displayed PNG image
SDL_Surface *background_surface = NULL;