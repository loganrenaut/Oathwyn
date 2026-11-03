#ifndef TILE_H
#define TILE_H

#include <stdbool.h>

typedef enum {
    TERRAIN_GROUND,
    TERRAIN_GRASS,
    TERRAIN_WALL,
    TERRAIN_WATER,
    TERRAIN_ICE,
    TTERRAIN_TREE,
    TERRAIN_CLIFF,
    TERRAIN_LAVA,
    TERRAIN_FIRE,
} TerrainType;

typedef struct {
    TerrainType type;
    bool walkable;
}Tile;

#endif