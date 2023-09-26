#include "../include/Game.h"
#include <iostream>

Game::Game() {

    title = "Snake";
    window_dimensions.first = 800;
    window_dimensions.second = 800;
    window_background = SURFACE_DEFAULT;
    game_tick = 0;
    tail_tick = 0;
    wait_time = 10;

    load_elements();

}


void Game::tick() {

    for (int i = 0; i < game_objects.size(); ++i) {
        if (game_objects[i].ID == SNAKE_HEAD) {
            game_objects[i].move();
        }
    }
    game_tick++;
    tail_tick++;
    if (tail_tick == 5) {
        std::cout << "speed increase" << '\n';
        for (int i = 0; i < game_objects.size(); ++i) {
        if (game_objects[i].ID == SNAKE_HEAD) {
            /* Grow Tail */
            }
        }   
        tail_tick = 0;
    }
    
}

void Game::load_elements() {

    create_object("Background", -1, "media/background.bmp", -1, 400, 400, 800, 800, 0.0, 0.0);
    create_object("Snake Head", 1, "media/snake_head.bmp", 1, 400, 400, 32, 32, 0.0, 3.5);

}

void Game::create_object(std::string name, int id, std::string path, int texture_id, int x, int y, int w, int h, double r, double v) {

    game_objects.push_back(GameObject(name, id, x, y, w, h, r, v, texture_id, path));

}

void Game::quit() {
    
}