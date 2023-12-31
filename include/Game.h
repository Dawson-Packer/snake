#include <string>
#include <vector>
#include "global.h"
#include "Object.h"
#include "Snake.h"

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
        void end_game(int points);
        double specified_rotation;
        void quit();

    private:
        std::vector<Object> objects;
        // Snake snake;
        Snake snake = Snake("Snake", 1, 400, 400, 64, 64, 0.0, 8.0, 1, "media/snake_head.bmp");
        Apple apple = Apple("Apple", 2, -99, -99, 40, 40, 0.0, 2, "media/apple.bmp");
        unsigned int game_tick;
        bool isEnd = false;
        void load_textures();
        void attempt_rotate(double rotation);
        void rotate_snake(double rotation);

        void drop_apple();


        void create_object(std::string name, int id, std::string path, int texture_id, int x, int y,
         int w, int h, double r);

        void load_elements();

        

};