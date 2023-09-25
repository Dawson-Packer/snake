#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "global.h"

class Window {
    public:
        Window( int width_, int height_ );

        bool isOpen;

        /// @brief Sets the title of the window
        /// @param title The string to set the title to
        void set_title(std::string title);

        /// @brief Loads default surface information
        /// @return Returns true on success
        bool load_media();

        /// @brief Takes input from user and runs associated actions
        void update_surface( int surface_type );

        /// @brief Kills the window and closes application
        void close();
    private:
        int height;
        int width;
        SDL_Renderer *renderer = NULL;
        SDL_Window *window = NULL;

        
        SDL_Surface* default_surface = NULL;
        SDL_Surface* screen_surface = NULL;
        SDL_Surface* top_surface = NULL;
        SDL_Surface* preloaded_surfaces[ SURFACE_TOTAL ];

        /// @brief Loads a surface with a BMP
        /// @param path The path to the image from the current directory
        /// @return Returns a surface containing the BMP
        SDL_Surface* load_surface( std::string path );
};