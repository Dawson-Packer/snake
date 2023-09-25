#pragma once
#include <string>
#include <C:/msys64/mingw64/include/SDL2/SDL.h>
//#include <SDL2/SDL.h>

enum surface_media {
    SURFACE_DEFAULT,
    SURFACE_KEYPRESS_UP,
    SURFACE_TOTAL
};

enum textures {
    TEXTURE_DEFAULT,
    TEXTURE_DOT,
    TEXTURE_TOTAL
};

enum log_type {
    LOG_GENERAL,
    LOG_ERROR,
    LOG_WARNING,
    LOG_ACTION,
    LOG_FLAG
};

struct _surface {
    int ID;
    std::string path;
};

struct _texture {
    int ID;
    std::string path;
    int x_pos;
    int y_pos;
};