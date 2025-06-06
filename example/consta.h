#pragma once

#ifndef CONSTA
#define CONSTA

#include <iostream>

#define CELLSIZE_M 10
#define CELLSIZE_N 10
#define CHANCE_FOOD 10

#define ENERGY_MAX 100

#define CELLSIZE_SCREEN 100.f

enum CellType {
    Type_Grass,
    Type_Hill,
    Type_Forest,
    Type_Stone,
    Type_Sand,
    Type_Snow,
    Type_Water,
    Type_End
};
enum TextureType {
    Texture_Grass,
    Texture_Hill,
    Texture_Forest,
    Texture_Stone,
    Texture_Sand,
    Texture_Snow,
    Texture_Water,
    Texture_Hide,
    Texture_Soup,
    Texture_End
};

static const std::string textureFiles[TextureType::Texture_End] =
{ "grass", "hill", "forest", "stone", "sand", "snow", "water", "hide", "soup" };

#endif
