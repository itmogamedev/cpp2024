#pragma once

#include "enemy.h"
#include "resources.h"

enum CellType {
	Cell_Grass,
	Cell_Hill,
	Cell_Forest,
	Cell_Stone,
	Cell_Sand,
	Cell_Snow,
	Cell_Water,
	Cell_End
};

class Cell : public sf::Drawable {
	sf::Vector2u position;

	bool               isHidden = true;
	bool               isFood   = false;
	CellType           cellType = Cell_Grass;
	sf::RectangleShape shape;

	void refresh_texture() {
		if (isHidden) {
			shape.setTexture(Resources::get_texture(TextureType::T_Hide));
		} else {
			if (isFood) {
				shape.setTexture(Resources::get_texture(TextureType::T_Soup));
			} else {
				shape.setTexture(Resources::get_texture(static_cast<TextureType>(cellType)));
			}
		}
	}

public:
	explicit Cell(const sf::Vector2u position, const CellType cell_type) : position(position), cellType(cell_type) {
		shape.setSize({CELL_SIZE_SCREEN, CELL_SIZE_SCREEN});
		shape.setPosition({position.x * CELL_SIZE_SCREEN, position.y * CELL_SIZE_SCREEN});
		shape.setTexture(Resources::get_texture(static_cast<TextureType>(cellType)));
	}

	Enemy* enemy = nullptr;

	[[nodiscard]] bool has_enemy() const {
		return enemy != nullptr;
	}

	[[nodiscard]] bool is_hidden() const {
		return isHidden;
	}
	void set_hidden(const bool hidden) {
		isHidden = hidden;
		refresh_texture();
	}

	[[nodiscard]] bool is_food() const {
		return isFood;
	}
	void set_food(const bool food) {
		isFood = food;
		refresh_texture();
	}

	[[nodiscard]] sf::Vector2u get_position() const {
		return position;
	}
	[[nodiscard]] CellType get_cell_type() const {
		return cellType;
	}

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
		target.draw(shape, states);
		if (!is_hidden() && enemy) {
			target.draw(*enemy, states);
		}
	}
};