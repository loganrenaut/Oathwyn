#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

typedef struct {
    float move_x;
    float move_y;

    bool jump;              //New pressed event
    bool jump_held;         //Currently held

    bool interact;          //New pressed event
    bool interact_held;     //Currently held
} GameInput;

typedef struct {
    bool up_held;
    bool down_held;
    bool left_held;
    bool right_held;

    bool jump_held;
    bool interact_held;

    bool jump_pending;
    bool interact_pending;

    unsigned int press_sequence;

    unsigned int up_sequence;
    unsigned int down_sequence;
    unsigned int left_sequence;
    unsigned int right_sequence;
} InputState;


#endif