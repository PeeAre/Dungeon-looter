#include <SDL2/SDL.h>

#ifndef LOAD_H
#define LOAD_H

int init();
int load_media();
int load_texture(char *path);
void free_sdl_resources();

#endif
