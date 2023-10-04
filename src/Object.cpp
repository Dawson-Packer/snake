#include <math.h>
#include "../include/Object.h"
#include <iostream>

Object::Object(std::string name_,
int ID,
int x_,
int y_,
int w_,
int h_,
double r_,
int texture_id,
std::string path) :
    name(name_), ID(ID), x(x_), y(y_), rotation(r_) {
        texture.ID = texture_id;
        texture.path = path;
        texture.dim.w = w_;
        texture.dim.h = h_;
        update_texture_data();
    }

void Object::setX(int x_) {
    x = x_; 
    update_texture_data();
    }

void Object::setY(int y_) {
    y = y_;
    update_texture_data();
    }

void Object::setRotation(double r_) {
    rotation = r_;
    update_texture_data();
    }

int Object::xPos() { return x; }

int Object::yPos() { return y; }

double Object::getRotation() { return rotation; }

void Object::update_texture_data() {
    texture.dim.x = x - (texture.dim.w / 2);
    texture.dim.y = y - (texture.dim.h / 2);
    texture.rotation = rotation;
}
