#include "../include/Game.h"
#include <iostream>

Game::Game() {
    title = "Snake";
    window_dimensions.first = 640;
    window_dimensions.second = 480;
    game_tick = 0;
    wait_time = 8;

    load_elements();

}


void Game::tick() {

    textures_changed = false;
    snake.move();
    if (snake.yPos() >= 480 - (snake.texture.dim.h / 2)) {
        rotate_snake(0.0);
        snake.setY(447);
    }
    if (snake.xPos() >= 640 - (snake.texture.dim.w / 2)) {
        rotate_snake(270.0);
        snake.setX(607);
    }
    if (snake.yPos() <= 0 + (snake.texture.dim.h / 2)) {
        rotate_snake(180.0);
        snake.setY(33);
    }
    if (snake.xPos() <= 0 + (snake.texture.dim.w / 2) &&
    (snake.yPos() < 480 - (snake.texture.dim.h / 2))) {
        rotate_snake(90.0);
        snake.setX(33);
    }
    if (snake.xPos() <= 0 || snake.xPos() >= 640 ||
    snake.yPos() <= 0 || snake.yPos() >= 480) end_game(-1);

    game_tick++;
    
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

void Game::rotate_snake(double rotation) {
    std::cout << "ROTATE" << '\n';
    snake.setRotation(rotation);
}

void Game::end_game(int points) {

    quit();
    objects.clear();
    create_object("End Game Background", -2, "media/end_background.bmp", -2, 400, 400, 800, 800,
    0.0);
    load_textures();
}

void Game::quit() {
    
    game_running = false;
}