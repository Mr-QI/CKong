cmake_minimum_required(VERSION 3.15)
project(CKong C)

set(CMAKE_C_STANDARD 99)

add_executable(
        CKong main.c
        str.c str.h
        palette.c palette.h
        tile.c tile.h
        sprite.c sprite.h
        tile_map.c tile_map.h
        actor.c actor.h
)