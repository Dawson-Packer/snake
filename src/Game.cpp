#include "../include/Game.h"
#include <iostream>

Game::Game() {

    title = "Snake";
    window_dimensions.first = 800;
    window_dimensions.second = 800;
    game_tick = 0;
    tail_tick = 0;
    wait_time = 10;

    load_elements();

}


void Game::tick() {

    textures_changed = false;
    for (int i = 0; i < game_objects.size(); ++i) {
        if (game_objects[i].ID == SNAKE_HEAD) {
            game_objects[i].move();
            //std::cout << game_objects[i].xPos() << " " << game_objects[i].yPos() << '\n';
            if (game_objects[i].yPos() >= 800 - (game_objects[i].texture.dim.h / 2))
            game_objects[i].setRotation(0.0);
            if (game_objects[i].xPos() >= 800 - (game_objects[i].texture.dim.w / 2))
            game_objects[i].setRotation(270.0);
            if (game_objects[i].yPos() <= 0 + (game_objects[i].texture.dim.h / 2))
            game_objects[i].setRotation(180.0);
            if (game_objects[i].xPos() <= 0 + (game_objects[i].texture.dim.w / 2) &&
            (game_objects[i].yPos() < 800 - (game_objects[i].texture.dim.h / 2)))
            game_objects[i].setRotation(90.0);
            if (game_objects[i].xPos() <= 0 || game_objects[i].xPos() >= 800 ||
            game_objects[i].yPos() <= 0 || game_objects[i].yPos() >= 800) end_game(-1);
            
            reload_texture(i);
            textures_changed = true;
        }
    }
    game_tick++;
    tail_tick++;
    if (tail_tick == 5) {
        for (int i = 0; i < game_objects.size(); ++i) {
        if (game_objects[i].ID == SNAKE_HEAD) {
            /* Grow Tail */
            }
        }   
        tail_tick = 0;
    }
    
}

void Game::reload_texture(int index) {

    textures[index].dim = game_objects[index].texture.dim;
    textures[index].rotation = game_objects[index].getRotation();
}

void Game::create_object(std::string name, int id, std::string path, int texture_id, int x, int y,
int w, int h, double r, double v) {

    game_objects.push_back(GameObject(name, id, x, y, w, h, r, v, texture_id, path));
    int last_index = game_objects.size() - 1;
    textures.push_back(game_objects[last_index].texture);

}

void Game::load_elements() {

    create_object("Background", -1, "media/background.bmp", -1, 400, 400, 800, 800, 0.0, 0.0);
    create_object("Snake Head", 1, "media/snake_head.bmp", 1, 400, 400, 64, 64, 0.0, 5.5);

}

void Game::rotate_snake(int rotation) {
    for(int i = 0; i < game_objects.size(); ++i) {
        if (game_objects[i].ID == SNAKE_HEAD) game_objects[i].setRotation(rotation);
    }
}

void Game::end_game(int points) {

    game_objects.clear();
    textures.clear();
    create_object("End Game Background", -2, "media/end_background.bmp", -2, 400, 400, 800, 800,
    0.0, 0.0);
    textures_changed = true;
}

void Game::quit() {
    
    game_running = false;
}