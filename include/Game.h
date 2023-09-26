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
        int window_background;
        std::pair<int, int> window_dimensions;
        std::vector<GameObject> game_objects;
        void create_object(std::string name, int id, std::string path, int texture_id, int x, int y, int w, int h, double r, double v);

        void quit();

    private:
        unsigned int game_tick;
        int tail_tick;


        void load_elements();

        

};