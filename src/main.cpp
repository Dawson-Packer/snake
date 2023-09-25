#include "../include/App.h"
#include <iostream> // <-- ONLY FOR TESTING AT THE MOMENT

// Compilation command: g++ main.cpp Window.cpp App.cpp Game.cpp -IC:\mingw64\include -I..\include -LC:\mingw64\lib -lmingw32 -lSDL2main -lSDL2 -o snake.exe
// g++ main.cpp Window.cpp App.cpp Game.cpp -IC:\msys64\mingw64\include -I..\include -LC:\msys64\mingw64\lib -lmingw32 -lSDL2main -lSDL2 -o snake.exe

int main( int argc, char *argv[] ) {

    App snake_game;

    while( snake_game.isRunning() ) {

        snake_game.run();

    }

    return 0;
}