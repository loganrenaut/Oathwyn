#ifndef INPUT_SDL_H
#define INPUT_SDL_H

#include "input.h"

void input_sdl_process_event(InputState *state, const SDL_Event *event);

#endif