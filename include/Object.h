#pragma once
#include "global.h"
#include <string>

class Object {
    public:
        Object(std::string name_ = "missingname",
        int ID = -99,
        int x_ = 0,
        int y_ = 0,
        int w_ = 64,
        int h_ = 64,
        double r_ = 0.0,
        int texture_id = 0,
        std::string path = "media/missingtexture.bmp");

        _texture texture;

        std::string name;
        void setX(int x_);
        void setY(int y_);
        void setRotation(double r_);

        int ID;

        int xPos();
        int yPos();
        double getRotation();
        void update_texture_data();

    private:
        int x, y;
        double rotation;
};