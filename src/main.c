#include <SDL3/SDL.h>

#include <stdbool.h>
#include <stdlib.h>


int main(void) 
{
    if(!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Oathwyn: SDL initialization failed: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Oathwyn Project",
        800,
        600,
        0
    );

    if (window == NULL) {
        SDL_Log("Oathwyn: Window creation failed: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Surface *surface = SDL_CreateSurface(
        400,
        200,
        SDL_PIXELFORMAT_RBGA32
    );

    if (surface == NULL) {
        SDL_Log("Error creating surface: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Surface *screen = SDL_GetWindowSurface(window);

    if(screen == NULL) {
        SDL_Log("Error getting window surface: %s", SDL_GetError());
        SDL_DestroySurface(surface);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Rect position;

    position.x = (screen->w - surface->w) / 2;
    position.y = (screen->h - surface->h) / 2;

    SDL_FillSurfaceRect(
        surface,
        NULL,
        SDL_MapSurfaceRBG(surface, 188, 169, 101)
    );

    SDL_BlitSurface(surface, NULL, screen, &position);

    SDL_UpdateWindowSurface(window);

    bool running = true;
    SDL_Event event;

    while(running) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        SDL_Delay(16);
    }

    SDL_DestroySurface(surface);
    surface = NULL;
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}