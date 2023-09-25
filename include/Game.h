#include <string>

class Game {
    public:
        Game();
        std::string title;

        /// @brief Executes all game actions necessary in one game tick
        void tick();

        int wait_time;
        std::pair<int, int> window_dimensions;

    private:
        unsigned int game_tick;
};