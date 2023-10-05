#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <C:/mingw64/include/SDL2/SDL.h>

const double PI = 3.14159;

enum GAME_OBJECTS {
    BACKGROUND = -1,
    DEFAULT,
    SNAKE_HEAD
};

enum log_type {
    LOG_GENERAL,
    LOG_ERROR,
    LOG_WARNING,
    LOG_ACTION,
    LOG_FLAG
};

struct _texture {
    int ID;
    std::string path;
    SDL_Rect dim;
    double rotation;
};

struct _node {
    int x;
    int y;
    struct _texture texture;
};