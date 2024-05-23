#include <stdio.h>
#include "load.h"
#include "params.h"
#include "render.h"

int main(int argc, char *args[])
{
  int quit = 0;
  SDL_Event e;

  init();

  while (!quit)
  {
    while (SDL_PollEvent(&e) != 0)
      if (e.type == SDL_QUIT)
        quit = 1;

    render();
  }

  free_sdl_resources();
  return 0;
}