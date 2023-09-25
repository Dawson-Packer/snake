#include <string>
#include "Window.h"
#include "global.h"



class App {
    public:
        App();
        App( int width_, int height_ );

        bool isRunning();

        void run();

    private:
        
        
        Window wd;
        SDL_Event e;
        std::string title;
        int app_width;
        int app_height;

        void input();

        void log(int type, std::string statement);
};