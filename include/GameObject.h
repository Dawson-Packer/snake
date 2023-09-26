#include "global.h"
#include <string>

class GameObject {
    public:
        GameObject(std::string name_ = "missingname", int ID, int x_ = 0, int y_ = 0, int w_ = 64, int h_ = 64, int r_ = 0, int v_ = 0, int texture_id = 0, std::string path);

        std::string name;
        void setX(int x_);
        void setY(int y_);
        void setRotation(double r_);
        void setVelocity(double v_);

        int ID;

        int xPos();
        int yPos();
        double rotation();
        double velocity();

        _texture texture;

        int move();

    private:
        int x, y, r, v;

        void update_texture_data();
};