#include "input.h"
#include <math.h>

GameInput input_consume(InputState *state) {

    GameInput input = {0};
    
    // Horizontal axis movement
    if(state->left_held && state->right_held){
        if(state->right_sequence >= state->left_sequence) {
            input.move_x = 1.00f;
        }
        else {
            input.move_x = -1.00f;
        }
    }
    else if (state->left_held) {
        input.move_x  = -1.00f;
    }
    else if (state->right_held)
    {
        input.move_x = 1.00f;
    }

    // Vertical axis movement
    if(state->up_held && state->down_held){
        if(state->up_sequence >= state->down_sequence) {
            input.move_y = 1.00f;
        }
        else {
            input.move_y = -1.00f;
        }
    }
    else if (state->down_held) {
        input.move_y  = -1.00f;
    }
    else if (state->up_held)
    {
        input.move_y = 1.00f;
    }

// Normalize diagonal movement to prevent increased movement speed
    if (input.move_x != 0.0f && input.move_y != 0.0f) {

        float magnitude = sqrtf(
            (input.move_x * input.move_x) + 
            (input.move_y * input.move_y)
        );
        
        input.move_x /= magnitude;
        input.move_y /= magnitude;
    }

    input.jump_held = state->jump_held;
    input.jump_pressed = state->jump_pending;

    input.interact_pressed = state->interact_pending;
    input.interact_held = state->interact_held;

    state->jump_pending = false;
    state->interact_pending = false;

    return input;
}