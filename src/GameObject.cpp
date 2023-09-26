#pragma once
#include <math.h>
#include "../include/GameObject.h"

GameObject::GameObject(std::string name_, int ID, int x_, int y_, int w_, int h_, int r_, int v_, int texture_id, std::string path) :
    name(name_), ID(ID), x(x_), y(y_), r(r_), v(v_) {
        texture.ID = texture_id;
        texture.path = path;
        texture.dim.w = w_;
        texture.dim.h = h_;
        texture.dim.x = x - (texture.dim.w / 2);
        texture.dim.h = y - (texture.dim.h / 2);
    }

void GameObject::setX(int x_) { x = x_; }

void GameObject::setY(int y_) { y = y_; }

void GameObject::setRotation(double r_) { r = r_; }

void GameObject::setVelocity(double v_) { v = v_; }

int GameObject::xPos() { return x; }

int GameObject::yPos() { return y; }

double GameObject::rotation() { return r; }

double GameObject::velocity() { return v; }

int GameObject::move() {

    x = x + int((v * cos(r * (PI / 180.0))));
    y = y + int((v * cos(r * (PI / 180.0))));

}

void GameObject::update_texture_data() {

}
