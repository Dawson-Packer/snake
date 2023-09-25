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

    load_texture( "../media/icon.bmp", 40, -40 );

    load_surface( "../media/background.bmp" );

}

void Game::load_texture( std::string path, int x, int y ) {

    textures.push_back( _texture() );
    int new_ID = textures.size() - 1;
    textures[ new_ID ].ID = new_ID;
    textures[ new_ID ].path = path;
    textures[ new_ID ].x_pos = x;
    textures[ new_ID ].y_pos = y;

}

void Game::load_surface( std::string path ) {

    surfaces.push_back( _surface() );
    int new_ID = surfaces.size() - 1;
    surfaces[ new_ID ].ID = new_ID;
    surfaces[ new_ID ].path = path;

}