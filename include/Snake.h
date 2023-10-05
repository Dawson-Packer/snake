#pragma once
#include "global.h"
#include "Object.h"
#include <string>

class Snake : public Object {
    public:
        Snake(std::string name_, 
        int ID,
        int x_,
        int y_,
        int w_,
        int h_,
        double r_,
        double v_,
        int texture_id,
        std::string path);

        bool isIntersecting = false;

        void setVelocity(double v_);
        double getVelocity();

        void move();
        void add_segment(int x_, int y_);

        std::vector<_node> tail_nodes;

    private:
        double velocity;
        double tail_wait_loop = 0;
};