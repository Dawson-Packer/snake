#include <string>
#include <vector>
#include "global.h"
#include "GameObject.h"

class Window {
    public:
        Window(int width_, int height_);

        bool isOpen;

        /// @brief Sets the title of the window
        /// @param title The string to set the title to
        void set_title(std::string title);

        void update(std::vector<GameObject> objects);

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
        SDL_Surface* load_surface(std::string path);

        SDL_Texture* load_texture(std::string path);

};