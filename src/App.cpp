#include "../include/App.h"



App::App() : wd(gm.window_dimensions.first, gm.window_dimensions.second) {

    wd.set_title(gm.title);
    wd.update(gm.game_objects);

}

App::App(int width_, int height_) : wd(width_, height_) {
    
    wd.set_title(gm.title);
    wd.update(gm.game_objects);

}

bool App::isRunning() {

    return wd.isOpen;

}

void App::run() {

    gm.tick();

    input();
    std::cout << gm.game_objects[1].xPos() << '\n';
    wd.update(gm.game_objects);

    SDL_Delay(gm.wait_time); // Must be at end of function
}


void App::input() {

    while ( SDL_PollEvent(&e) ) {

        if (e.type == SDL_QUIT) {
            gm.quit();
            wd.close();
        }

        else if (e.type == SDL_KEYDOWN) {

            switch (e.key.keysym.sym) {

                case SDLK_UP : {
                    log(LOG_ACTION, "KEY_UP pressed");
                    gm.rotate_snake(270);
                }
                break;
                case SDLK_DOWN : {
                    log(LOG_ACTION, "KEY_DOWN pressed");
                    gm.rotate_snake(90);
                }
                break;
                case SDLK_RIGHT : {
                    log(LOG_ACTION, "KEY_RIGHT pressed");
                    gm.rotate_snake(0);
                }
                break;
                case SDLK_LEFT : {
                    log(LOG_ACTION, "KEY_LEFT pressed");
                    gm.rotate_snake(180);
                }
                break;

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