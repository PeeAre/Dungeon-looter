#include <stdio.h>
#include "load.h"
#include "params.h"
#include "render.h"
#include "events.h"

int main(int argc, char *args[])
{
  int quit = 0;

  if (init())
    return 1;

  while (!quit) // game loop
  {
    render();
    quit = handle_events();
  }

  free_sdl_resources();

  return 0;
}