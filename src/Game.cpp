#include "../include/Game.h"

Game::Game() {

    title = "Snake";
    window_dimensions.first = 800;
    window_dimensions.second = 800;
    game_tick = 0;
    wait_time = 10;

}


void Game::tick() {

    game_tick++;
    
}

