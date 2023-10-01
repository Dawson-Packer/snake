#include <string>
#include "Window.h"
#include "Game.h"
#include "global.h"



class App {
    public:
        App();
        App(int width_, int height_);

        /// @brief Function that determines whether the app is running
        /// @return Returns true if the app is running
        bool isRunning();
        bool isRestarting;

        /// @brief Executed all app processes in one loop iteration
        void run();

    private:
        
        Game gm;
        Window wd;
        SDL_Event e;


        void input();


        void log(int type, std::string statement);

        void restart();
        void quit();
};