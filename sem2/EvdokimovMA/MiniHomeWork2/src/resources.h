#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

enum TextureType {
    T_Grass,
    T_Hill,
    T_Forest,
    T_Stone,
    T_Sand,
    T_Snow,
    T_Water,
    T_Hide,
    T_Soup,
    T_TILES_END,
	T_Enemy,
	T_END
};

class Resources {
	sf::Texture textures[T_END];
public:
  	Resources() {
  		textures[T_Grass]  = sf::Texture("assets/grass.png");
  		textures[T_Hill]   = sf::Texture("assets/hill.png");
  		textures[T_Forest] = sf::Texture("assets/forest.png");
  		textures[T_Stone]  = sf::Texture("assets/stone.png");
  		textures[T_Sand]   = sf::Texture("assets/sand.png");
  		textures[T_Snow]   = sf::Texture("assets/snow.png");
  		textures[T_Water]  = sf::Texture("assets/water.png");
  		textures[T_Hide]   = sf::Texture("assets/hide.png");
  		textures[T_Soup]   = sf::Texture("assets/soup.png");
  		textures[T_Enemy]  = sf::Texture("assets/enemy.png");

        std::cout << "TileSet initialized" << std::endl;
	}

	[[nodiscard]] static const sf::Texture* get_texture(const TextureType type) {
		if (type >= T_END) {
			std::cerr << "Invalid texture type: " << type << std::endl;
			throw std::out_of_range("Invalid texture type");
		}
		return &get_instance().textures[type];
	}

    [[nodiscard]] static Resources& get_instance() {
		static Resources instance;
		return instance;
	}
};