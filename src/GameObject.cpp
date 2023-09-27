#include <math.h>
#include "../include/GameObject.h"
#include <iostream>

GameObject::GameObject(std::string name_, int ID, int x_, int y_, int w_, int h_, double r_,
double v_, int texture_id, std::string path) :
    name(name_), ID(ID), x(x_), y(y_), r(r_), v(v_) {
        texture.ID = texture_id;
        texture.path = path;
        texture.dim.w = w_;
        texture.dim.h = h_;
        update_texture_data();
    }

void GameObject::setX(int x_) {
    x = x_; 
    update_texture_data();
    }

void GameObject::setY(int y_) {
    y = y_;
    update_texture_data();
    }

void GameObject::setRotation(double r_) {
    r = r_;
    update_texture_data();
    }

void GameObject::setVelocity(double v_) { v = v_; }

int GameObject::xPos() { return x; }

int GameObject::yPos() { return y; }

double GameObject::rotation() { return r; }

double GameObject::velocity() { return v; }

void GameObject::move() {

    
    x = x + int((v * cos(r * (PI / 180.0))));
    y = y + int((v * sin(r * (PI / 180.0))));
    std::cout << "move: " << int((v * cos(r * (PI / 180.0)))) << int((v * sin(r * (PI / 180.0))))
    << '\n';
    update_texture_data();
}

void GameObject::update_texture_data() {
    texture.dim.x = x - (texture.dim.w / 2);
    texture.dim.y = y - (texture.dim.h / 2);
    texture.r = r;
}