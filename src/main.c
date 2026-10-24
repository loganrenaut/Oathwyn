#include <SDL3/SDL.h>
#include <stdbool.h>

int main(void) 
{
    if(!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Oathwyn: SDL initialization failed: %s", SDL_GetError());
        return 1;
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
        return 1;
    }

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

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}