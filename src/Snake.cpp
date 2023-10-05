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
    add_segment(tail_nodes[0].x - 16, tail_nodes[0].y);
    add_segment(tail_nodes[1].x - 16, tail_nodes[1].y);
    add_segment(tail_nodes[2].x - 16, tail_nodes[2].y);
    add_segment(tail_nodes[3].x - 16, tail_nodes[3].y);
    add_segment(tail_nodes[4].x - 16, tail_nodes[4].y);
    add_segment(tail_nodes[5].x - 16, tail_nodes[5].y);
    add_segment(tail_nodes[6].x - 16, tail_nodes[6].y);



}

void Snake::setVelocity(double v_) { velocity = v_; }

double Snake::getVelocity() { return velocity; }

void Snake::move() {

    tail_wait_loop += velocity;
    if (tail_wait_loop >= 16) tail_wait_loop = 0;
    setX(xPos() + int((velocity * cos(getRotation() * (PI / 180.0)))));
    setY(yPos() + int((velocity * sin(getRotation() * (PI / 180.0)))));
    if (tail_wait_loop == 0) {
        for (int i = tail_nodes.size() - 1; i > 0; --i) {
            std::cout << "For segment " << i << ", old coords: " << tail_nodes[i].x << " " << tail_nodes[i].y << '\n';
            tail_nodes[i].x = tail_nodes[i - 1].x /*- (16 * int(cos(getRotation() * (PI / 180.0))))*/;
            tail_nodes[i].y = tail_nodes[i - 1].y /*- (16 * int(sin(getRotation() * (PI / 180.0))))*/;
            std::cout << "New coords: " << tail_nodes[i].x << " " << tail_nodes[i].y << '\n';
            tail_nodes[i].texture.dim.x = tail_nodes[i].x - (tail_nodes[i].texture.dim.w / 2);
            tail_nodes[i].texture.dim.y = tail_nodes[i].y - (tail_nodes[i].texture.dim.h / 2);
        }
        std::cout << "For segment " << "0" << ", old coords: " << tail_nodes[0].x << " " << tail_nodes[0].y << '\n';
        tail_nodes[0].x = xPos() - int(16 * (cos(getRotation() * (PI / 180.0))));
        tail_nodes[0].y = yPos() - int(16 * (sin(getRotation() * (PI / 180.0))));
        std::cout << "New coords: " << tail_nodes[0].x << " " << tail_nodes[0].y << '\n';
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
