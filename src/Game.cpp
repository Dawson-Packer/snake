#include "../include/Game.h"

Game::Game() {

    title = "Snake";
    game_tick = 0;
    wait_time = 10;

}


void Game::tick() {

    game_tick++;
    
}

