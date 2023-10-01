#pragma once
#include <string>
#include <iostream>
#include <SDL2/SDL.h>

const double PI = 3.14159;

enum GAME_OBJECTS {
    BACKGROUND = -1,
    DEFAULT,
    SNAKE_HEAD
};

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
    SDL_Rect dim;
    double rotation;
};