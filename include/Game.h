#include <string>
#include <vector>
#include "global.h"

class Game {
    public:
        Game();
        std::string title;

        /// @brief Executes all game actions necessary in one game tick
        void tick();

        int wait_time;
        int window_background;
        std::pair<int, int> window_dimensions;
        std::vector<_texture> textures;
        std::vector<_surface> surfaces;
        void load_texture(int id, std::string path, int x, int y, int h, int w);

        void quit();

    private:
        unsigned int game_tick;


        void load_media();

        

};