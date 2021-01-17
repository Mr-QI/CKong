//
// Created by QDS on 2021/1/17.
//

#ifndef CKONG_ACTOR_H
#define CKONG_ACTOR_

#include <stdint.h>

typedef enum actor_flags{
    none = 0b00000000;
}actor_flags_t;

typedef struct animation_frame_tile{
    uint16_t x_offset;
    uint16_t y_offset;
    uint16_t tile;
    uint8_t flags;
    uint8_t palette;
}animation_frame_tile_t;

typedef struct animation_frame{
    uint16_t delay;
    uint8_t tile_count;
    animation_frame_tile_t tiles[32];
}animation_frame_t;

typedef struct animation{
    uint8_t frame_count;
    animation_frame_t frames[32];
}animation_t;

typedef struct actor{
    uint16_t x;
    uint16_t y;
    uint8_t frame;
    uint16_t data1;
    uint16_t data2;
    animation_t* animation;
}actor_t;

#endif //CKONG_ACTOR_H
