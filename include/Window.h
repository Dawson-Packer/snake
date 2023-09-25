#include <SDL2/SDL.h>
#include <string>
#include <iostream>
//#include "Event.h"

class Window {
    public:
        Window( int width_, int height_ );
        bool isOpen;

        /// @brief Loads default surface information
        /// @return Returns true on success
        bool load_media();

        /// @brief Takes input from user and runs associated actions
        void update();

        /// @brief Kills the window and closes application
        void close();
    private:
        int height;
        int width;
        SDL_Event event;
        SDL_Renderer *renderer = NULL;
        SDL_Window *window = NULL;

        enum all_surfaces {
            KEYPRESS_UP,
            INPUT_TOTAL
        };
        SDL_Surface* default_surface = NULL;
        SDL_Surface* screen_surface = NULL;
        SDL_Surface* top_surface = NULL;
        SDL_Surface* all_surfaces[ INPUT_TOTAL ];

        /// @brief Loads a surface with a BMP
        /// @param path The path to the image from the current directory
        /// @return Returns a surface containing the BMP
        SDL_Surface* load_surface( std::string path );
};