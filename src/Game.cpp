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
    // for (int i = 0; i < objects.size(); ++i) {
    //     if (objects[i].ID == SNAKE_HEAD) {
    //         objects[i].move();
    //         //std::cout << objects[i].xPos() << " " << objects[i].yPos() << '\n';
    //         if (objects[i].yPos() >= 800 - (objects[i].texture.dim.h / 2)) {
    //             rotate_snake(0.0);
    //             objects[i].setY(767);
    //         }
    //         if (objects[i].xPos() >= 800 - (objects[i].texture.dim.w / 2)) {
    //             rotate_snake(270.0);
    //             objects[i].setX(767);
    //         }
    //         if (objects[i].yPos() <= 0 + (objects[i].texture.dim.h / 2)) {
    //             rotate_snake(180.0);
    //             objects[i].setY(33);
    //         }
    //         if (objects[i].xPos() <= 0 + (objects[i].texture.dim.w / 2) &&
    //         (objects[i].yPos() < 800 - (objects[i].texture.dim.h / 2))) {
    //             rotate_snake(90.0);
    //             objects[i].setX(33);
    //         }
    //         if (objects[i].xPos() <= 0 || objects[i].xPos() >= 800 ||
    //         objects[i].yPos() <= 0 || objects[i].yPos() >= 800) end_game(-1);
    //         objects[tail_segment].tail_grow(); 

    //         reload_texture(i);
    //         textures_changed = true;
    //     }
    // }
    game_tick++;
    tail_tick++;
    if (tail_tick == 20) {
        /* shrink tail code*/
        tail_tick = 0;
    }
    
    load_textures();

}

void Game::load_textures() {

    textures.clear();
    for (int i = 0; i < objects.size(); ++i) 
    textures.push_back(objects[i].texture);
    for (int i = snake.tail_nodes.size() - 1; i >= 0; --i) 
    textures.push_back(snake.tail_nodes[i].texture);
    textures.push_back(snake.texture);
}

void Game::create_object(std::string name,
int id,
std::string path,
int texture_id,
int x,
int y,
int w,
int h,
double r) {

    objects.push_back(Object(name, id, x, y, w, h, r, texture_id, path));
    int last_index = objects.size() - 1;
    textures.push_back(objects[last_index].texture);

}

void Game::load_elements() {

    create_object("Background", -1, "media/background.bmp", -1, 400, 400, 800, 800, 0.0);

}

void Game::rotate_snake(int rotation) {
    for(int i = 0; i < objects.size(); ++i) {
        if (objects[i].ID == SNAKE_HEAD) {
            objects[i].setRotation(rotation);
        }
    }
    tail_segment++;
}

void Game::end_game(int points) {

    objects.clear();
    textures.clear();
    create_object("End Game Background", -2, "media/end_background.bmp", -2, 400, 400, 800, 800,
    0.0);
    textures_changed = true;
}

void Game::quit() {
    
    game_running = false;
}