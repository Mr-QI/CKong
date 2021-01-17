//
// Created by QDS on 2021/1/17.
//

#ifndef CKONG_SPRITE_H
#define CKONG_SPRITE_H

#include <stdint.h>

const uint8_t sprite_width = 16;
const uint8_t sprite_height = 16;
const uint8_t sprite_max = 128;

typedef struct sprite_bitmap{
    uint8_t data[sprite_width * sprite_height];
}sprite_bitmap_t;

#endif //CKONG_SPRITE_H
