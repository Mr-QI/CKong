//
// Created by QDS on 2021/1/17.
//

#ifndef CKONG_PALETTE_H
#define CKONG_PALETTE_H

#include <stdint.h>

const uint8_t palette_max = 64;

typedef struct palette_entry{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
}palette_entry_t;

typedef struct palette{
    palette_entry_t entries[4];
}palette_t;

#endif //CKONG_PALETTE_H
