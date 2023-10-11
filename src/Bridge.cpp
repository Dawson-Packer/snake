#include "../include/Bridge.h"



Bridge::Bridge() : wd(gm.window_dimensions.first, gm.window_dimensions.second) {
    wd.set_title(gm.title);
    wd.update(gm.textures);

}

Bridge::Bridge(int width_, int height_) : wd(width_, height_) {
    
    wd.set_title(gm.title);
    wd.update(gm.textures);

}

bool Bridge::isRunning() {

    return wd.isOpen;

}

void Bridge::run() {

    if (gm.game_restarting) restart();
    if (!gm.game_running) quit();

    gm.tick();

    input();
    wd.update(gm.textures);

    SDL_Delay(gm.wait_time); // Must be at end of function
}


void Bridge::input() {

    while ( SDL_PollEvent(&e) ) {

        if (e.type == SDL_QUIT) {
            gm.quit();
            wd.close();
            quit();
        }

        else if (e.type == SDL_KEYDOWN) {

            switch (e.key.keysym.sym) {

                case SDLK_UP : {
                    log(LOG_ACTION, "KEY_UP pressed");
                    gm.specified_rotation = 270.0;
                }
                break;
                case SDLK_DOWN : {
                    log(LOG_ACTION, "KEY_DOWN pressed");
                    gm.specified_rotation = 90.0;
                }
                break;
                case SDLK_RIGHT : {
                    log(LOG_ACTION, "KEY_RIGHT pressed");
                    gm.specified_rotation = 0.0;
                }
                break;
                case SDLK_LEFT : {
                    log(LOG_ACTION, "KEY_LEFT pressed");
                    gm.specified_rotation = 180.0; 
                }
                break;

            }

        }

    }
    
}



void Bridge::log(int type, std::string statement) {
    
    switch (type) {
        
        case LOG_GENERAL: std::cout << ">>> " << statement << '\n'; break;
        case LOG_ERROR: std::cout << "[ERROR] " << statement << '\n'; break;
        case LOG_WARNING: std::cout << "[WARNING] " << statement << '\n'; break;
        case LOG_ACTION: std::cout << ">>> " << statement << '\n'; break;
        case LOG_FLAG: std::cout << "!!! " << statement << '\n'; break;
        default: std::cout << "[?] " << statement << '\n'; break;

    }

}

void Bridge::restart() {
    
    wd.close();
    isRestarting = true;
}

void Bridge::quit() {
    wd.close();
}