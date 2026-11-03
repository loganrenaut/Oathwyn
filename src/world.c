#include "world.h"

#include <stdint.h>
#include <stdlib.h>

bool map_init(Map *map, int width, int height) {

    if (map == NULL) return false;

    map->width = 0;
    map->height = 0;
    map->tiles = NULL;

    if (width <= 0 || height <= 0) return NULL;

    size_t w = (size_t) width;
    size_t h = (size_t) height;

    // prevent integer overflow when calculating memory allocation size
    if (w > SIZE_MAX / sizeof(Tile) / h) return false;

    Tile *tiles = calloc(w * h, sizeof(Tile));

    if (tiles == NULL) return false;

    map->width = width;
    map->height = height;
    map->tiles = tiles;

    return true;
}

    Tile *map_get_tile(Map *map, int x, int y) {

        if(map == NULL || map->tiles == NULL) {return NULL;}

        if (x < 0 || 
            y < 0 || 
            x >= map->width || 
            y >= map->height) {return NULL;}
        
        size_t index = (size_t)y * (size_t)map->width + (size_t)x;

        return &map->tiles[index];
    }

    void map_destroy(Map *map) {
        if (map == NULL) return;

        free(map->tiles);

        map->tiles = NULL;
        map->width = 0;
        map->height = 0;
    }
