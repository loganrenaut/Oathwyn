#include "input.h"

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

    return input;
}