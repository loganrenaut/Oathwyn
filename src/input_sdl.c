#include <SDL3/SDL.h>
#include "input_sdl.h"

void input_sdl_process_event(InputState *state, const SDL_Event *event) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if(event.type == SDL_EVENT_KEY_DOWN) {
            if(event.key.scancode == SDL_SCANCODE_W) {
                
            }
        }
    }
}