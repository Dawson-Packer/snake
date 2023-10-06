#include "../include/App.h"
#include <time.h>

// Compilation command: g++ src/main.cpp src/Window.cpp src/App.cpp src/Game.cpp src/Object.cpp src/Snake.cpp -IC:\mingw64\include -I\include -LC:\mingw64\lib -lmingw32 -lSDL2main -lSDL2 -o snake.exe

int main( int argc, char *argv[] ) {

    srand (time(NULL));
    bool restart = true;


    while (restart) {
        // restart = false;

        App snake_game;

        while(snake_game.isRunning()) {

            snake_game.run();

        }
        restart = snake_game.isRestarting;
    }

    return 0;
}