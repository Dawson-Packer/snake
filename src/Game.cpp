#include "../include/Game.h"

Game::Game() {

    title = "Snake";
    window_dimensions.first = 800;
    window_dimensions.second = 800;
    window_background = SURFACE_DEFAULT;
    game_tick = 0;
    wait_time = 10;

    load_elements();

}


void Game::tick() {


    game_tick++;
    
}

void Game::load_elements() {

    create_object("Background", -1, "media/background.bmp", -1, 400, 400, 800, 800, 0, 0);
    create_object("Snake Head", 1, "media/snake_head.bmp", 1, 400, 400, 64, 64, 0.0, 0.5);
    //load_texture(-1, "media/background.bmp", 400, 400, 800, 800, 0);
    //load_texture(1, "media/snake_head.bmp", 400, 400, 64, 64, 0);
    

}

void Game::create_object(std::string name, int id, std::string path, int texture_id, int x, int y, int w, int h, double r, double v) {

    game_objects.push_back(GameObject(name, id, x, y, w, h, r, v, texture_id, path));

}

void Game::quit() {
    
}