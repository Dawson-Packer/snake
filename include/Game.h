#include <string>
#include <vector>
#include "global.h"
#include "GameObject.h"

class Game {
    public:
        Game();
        std::string title;

        /// @brief Executes all game actions necessary in one game tick
        void tick();

        int wait_time;
        bool textures_changed = false;
        bool game_running = true;
        bool game_restarting = false;
        std::pair<int, int> window_dimensions;
        std::vector<_texture> textures;
        
        /// @brief Rotates snake to the input in degrees
        /// @param rotation The rotation value in degrees
        void rotate_snake(int rotation);
        void end_game(int points);

        void quit();

    private:
        std::vector<GameObject> game_objects;
        
        unsigned int game_tick;
        int tail_tick;

        void reload_texture(int index);
        void create_object(std::string name, int id, std::string path, int texture_id, int x, int y,
         int w, int h, double r, double v);

        void load_elements();

        

};