#include "../include/App.h"



App::App() : wd( 800, 800 ) {
    title = "Snake";
    wd.set_title( title );
}

App::App( int width_, int height_ ) : wd( width_, height_ ) {
    title = "Snake";
    wd.set_title( title );
}

bool App::isRunning() {
    return wd.isOpen;
}

void App::run() {
    input();
}


void App::input() {
    while ( SDL_PollEvent( &e) ) {

        if ( e.type == SDL_QUIT ) wd.close();

        else if ( e.type == SDL_KEYDOWN ) {
            switch ( e.key.keysym.sym ) {
                case SDLK_UP : {
                    log( LOG_ACTION, "KEY_UP pressed" );
                    wd.update_surface( SURFACE_KEYPRESS_UP );
                }
            }
        }
    }
}

void App::log(int type, std::string statement) {
    
    switch (type) {
        
        case LOG_GENERAL: std::cout << ">>> " << statement << '\n'; break;
        case LOG_ERROR: std::cout << "[ERROR] " << statement << '\n'; break;
        case LOG_WARNING: std::cout << "[WARNING] " << statement << '\n'; break;
        case LOG_ACTION: std::cout << ">>> " << statement << '\n'; break;
        case LOG_FLAG: std::cout << "!!! " << statement << '\n'; break;
        default: std::cout << "[?] " << statement << '\n'; break;

    }

}