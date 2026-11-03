#ifndef WORLD_H
#define WORLD_H

#include "tile.h"
#include <stdbool.h>

typedef struct {
    int width;
    int height;
    Tile *tiles;
} Map;

// Allocate a map of requested dimension
bool map_init(Map *map, int width, int height);

//Return a tile or null coordinates are invalid
Tile *map_get_tile(Map *map, int x, int y);

// Release map allocated memory
void map_destroy(Map *map);

#endif