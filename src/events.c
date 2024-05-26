#include "events.h"
#include "params.h"
#include "queue.h"

int handle_events()
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            return 1;

        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_e)
                printf("pressed \"e\"\n"); // some handler
        }
    }

    return 0;
}