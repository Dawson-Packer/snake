#include "../include/Texture.h"

Texture::Texture(int ID, int x_, int y_, int w_, int h_, double r_, std::string path) {
    
    texture_data.ID = ID;
    texture_data.dim.x = x_ - (w_ / 2);
    texture_data.dim.y = y_ - (h_ / 2);
    texture_data.dim.w = w_;
    texture_data.dim.h = h_;
    texture_data.path = path;
    texture_data.rotation = r_;



}