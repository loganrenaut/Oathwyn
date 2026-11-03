#include "world.h"

#include <assert.h>
#include <stdio.h>

int main(void) 
{
    Map map = {0};

    //Test 1: Initialize 10 x 5 map.
    assert(map_init(&map, 10, 5));
    assert(map.width == 10);
    assert(map.height == 5);
    assert(map.tiles != NULL);
    printf("PASS: map initialized\n");

    //Test 2: Access + modify a tile. 
    Tile *tile = map_get_tile(&map, 3, 2);
    assert(tile != NULL);

    tile->type = TERRAIN_FIRE;
    tile->walkable = true;

    assert(tile->type == TERRAIN_FIRE);
    assert(tile->walkable);
    printf("PASS: tile access and modification\n");

    //Test 3: Reject invalid coordinates
    assert(map_get_tile(&map, -1, 0) == NULL);
    assert(map_get_tile(&map, 10, 0) == NULL);
    assert(map_get_tile(&map, 0, 5) == NULL);
    assert(map_get_tile(&map, 0, -1) == NULL);
    printf("PASS: out-of-bounds coordinates\n");

    //Test 4: Reject invalid dimensions
    Map invalid_map = {0};

    assert(!map_init(&invalid_map, 0 ,5));
    assert(!map_init(&invalid_map, 10, -1));
    printf("PASS: invalid dimensions rejected\n");

    //Test 5: Destroy map safely
    map_destroy(&map);

    assert(map.tiles == NULL);
    assert(map.width == 0);
    assert(map.height == 0);
    printf("PASS: map destruction\n");

    puts("All world tests passed.");
    
    return 0;
}