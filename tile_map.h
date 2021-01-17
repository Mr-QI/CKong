//
// Created by QDS on 2021/1/17.
//

#ifndef CKONG_TILE_MAP_H
#define CKONG_TILE_MAP_H

#include <stdint.h>

const uint8_t tile_map_width = 32;
const uint8_t  tile_map_height = 32;

typedef struct tile_map_entry{
    uint16_t tile;
    uint8_t palette;
    uint8_t flags;
}tile_map_entry_t;

#endif //CKONG_TILE_MAP_H
