#include <C:/msys64/mingw64/include/SDL2/SDL.h>
//#include <SDL2/SDL.H>
#include <string>
#include <vector>
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
        //bool load_media( std::vector<_texture> textures, std::vector<_surface> surfaces );

        void update( std::vector<_texture> textures, std::vector<_surface> surfaces );

        /// @brief Takes input from user and runs associated actions
        //void render_surface( int surface_type );

        /// @brief Render a texture at a specific position on the screen
        /// @param texture_id The ID of the texture to render
        /// @param x The x position to render the texture at
        /// @param y The y position to render the texture at
        //void render_texture( int texture_id, int x, int y );

        /// @brief Kills the window and closes application
        void close();
    private:
        int height;
        int width;
        SDL_Renderer *renderer = NULL;
        SDL_Window *window = NULL;

        SDL_Surface* icon = NULL;
        SDL_Surface* default_surface = NULL;
        SDL_Surface* screen_surface = NULL;
        SDL_Surface* top_surface = NULL;
        SDL_Surface* preloaded_surfaces[ SURFACE_TOTAL ];

        SDL_Texture* all_textures[ TEXTURE_TOTAL ];

        /// @brief Loads a surface with a BMP
        /// @param path The path to the image from the current directory
        /// @return Returns a surface containing the BMP
        SDL_Surface* load_surface( std::string path );

        SDL_Texture* load_texture( std::string path );

};