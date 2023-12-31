#include <math.h>
#include "../include/Snake.h"
#include <iostream>

Snake::Snake(std::string name_, 
int ID,
int x_,
int y_,
int w_,
int h_,
double r_,
double v_,
int texture_id,
std::string path) :
Object(name_, ID, x_, y_, w_, h_, r_, texture_id, path),
    velocity(v_) {

    add_segment(xPos() - 16, yPos());
    for (int i = 1; i < 10; ++i) add_segment(tail_nodes[i - 1].x - 16, tail_nodes[i - 1].y);
    // last_tail_coords = {xPos(), yPos()};
}

void Snake::setVelocity(double v_) { velocity = v_; }

double Snake::getVelocity() { return velocity; }

void Snake::move() {

    // tail_textures.clear();
    tail_wait_loop += velocity;
    if (tail_wait_loop >= 16) tail_wait_loop = 0;
    setX(xPos() + int((velocity * cos(getRotation() * (PI / 180.0)))));
    setY(yPos() + int((velocity * sin(getRotation() * (PI / 180.0)))));
    if (tail_wait_loop == 0) {
        for (int i = tail_nodes.size() - 1; i > 0; --i) {
            tail_nodes[i].x = tail_nodes[i - 1].x;
            tail_nodes[i].y = tail_nodes[i - 1].y;
            tail_nodes[i].texture.dim.x = tail_nodes[i].x - (tail_nodes[i].texture.dim.w / 2);
            tail_nodes[i].texture.dim.y = tail_nodes[i].y - (tail_nodes[i].texture.dim.h / 2);
            if ( i > 1 && (fabs(xPos() - tail_nodes[i].x) <= 8 && fabs(yPos() - tail_nodes[i].y) <= 8)) isIntersecting = true;
            // if (tail_nodes[i].y == last_tail_coords.second) ++tail_count.second;
            // else if (tail_nodes[i].x != last_tail_coords.first) {
            //     std::cout << "y change: " << i << '\n';
            //     tail_textures.push_back(_texture());
            //     int end = tail_textures.size() - 1;
            //     tail_textures[end].path = "media/tail.bmp";
            //     tail_textures[end].dim.w = 16 * tail_count.second;
            //     tail_textures[end].dim.h = 16;
            //     tail_textures[end].dim.x = tail_nodes[i].texture.dim.x - (16 * tail_count.second);
            //     tail_textures[end].dim.y = last_tail_coords.first - (tail_textures[end].dim.h / 2);
            //     tail_count.second = 1;
            // }
            // if (tail_nodes[i].x == last_tail_coords.first) ++tail_count.first;
            // else if (tail_nodes[i].y != last_tail_coords.second) {
            //     std::cout << "x change: " << i << '\n';
            //     tail_textures.push_back(_texture());
            //     int end = tail_textures.size() - 1;
            //     tail_textures[end].path = "media/tail.bmp";
            //     tail_textures[end].dim.w = 16;
            //     tail_textures[end].dim.h = 16 * tail_count.first;
            //     tail_textures[end].dim.x = last_tail_coords.first - (tail_textures[end].dim.w / 2);
            //     tail_textures[end].dim.y = tail_nodes[i].texture.dim.y - (16 * tail_count.first);
            //     tail_count.first = 1;
            // }
            // last_tail_coords = {tail_nodes[i].x, tail_nodes[i].y};
            
        }
        tail_nodes[0].x = xPos() - int(16 * (cos(getRotation() * (PI / 180.0))));
        tail_nodes[0].y = yPos() - int(16 * (sin(getRotation() * (PI / 180.0))));
        tail_nodes[0].texture.dim.x = tail_nodes[0].x - (tail_nodes[0].texture.dim.w / 2);
        tail_nodes[0].texture.dim.y = tail_nodes[0].y - (tail_nodes[0].texture.dim.h / 2);
    }
    update_texture_data();
}

void Snake::add_segment(int x_, int y_) {
    tail_nodes.push_back(_node());
    int end = tail_nodes.size() - 1;
    tail_nodes[end].x = x_;
    tail_nodes[end].y = y_;
    tail_nodes[end].texture.path = "media/tail.bmp";
    tail_nodes[end].texture.rotation = 0.0;
    tail_nodes[end].texture.dim.h = 16;
    tail_nodes[end].texture.dim.w = 16;
    tail_nodes[end].texture.dim.x = tail_nodes[end].x - (tail_nodes[end].texture.dim.w / 2);
    tail_nodes[end].texture.dim.y = tail_nodes[end].y - (tail_nodes[end].texture.dim.h / 2);
}

Apple::Apple(std::string name_, 
        int ID,
        int x_,
        int y_,
        int w_,
        int h_,
        double r_,
        int texture_id,
        std::string path) : Object(name_, ID, x_, y_, w_, h_, r_, texture_id, path) { }