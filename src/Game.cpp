#include "../include/Game.h"

Game::Game() {

    title = "Snake";
    window_dimensions.first = 800;
    window_dimensions.second = 800;
    window_background = SURFACE_DEFAULT;
    game_tick = 0;
    wait_time = 10;

    load_media();

}


void Game::tick() {

    game_tick++;
    
}

void Game::load_media() {

    load_texture(-1, "../media/background.bmp", 0, 0, 800, 800);

}

void Game::load_texture(int id, std::string path, int x, int y, int h, int w) {

    textures.push_back(_texture());
    int new_ID = textures.size() - 1;
    textures[new_ID].ID = id;
    textures[new_ID].path = path;
    textures[new_ID].dim.x = x;
    textures[new_ID].dim.y = y;
    textures[new_ID].dim.h = h;
    textures[new_ID].dim.w = w;

}

void Game::quit() {
    
}