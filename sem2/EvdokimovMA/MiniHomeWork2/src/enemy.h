#pragma once

#include <cmath>
#include <bits/algorithmfwd.h>
#include <SFML/Graphics.hpp>
#include "resources.h"

class Enemy final : public sf::Drawable {
  int health = 100;
  sf::RectangleShape shape;
  float damage_time = -999.0f;

public:
  explicit Enemy(const sf::Vector2u position) {
    shape.setSize({CELL_SIZE_SCREEN, CELL_SIZE_SCREEN});
    shape.setTexture(Resources::get_texture(TextureType::T_Enemy));

    shape.setOrigin({CELL_SIZE_SCREEN / 2, CELL_SIZE_SCREEN / 2});
    shape.setScale({0.75f, 0.75f});
    shape.setPosition({(position.x + 0.5f) * CELL_SIZE_SCREEN, (position.y + 0.5f) * CELL_SIZE_SCREEN});
  }

  bool hit() {
    health -= 10;
    damage_time = Time::get().time();

    if (health <= 0) {
      return true;
    }

    return false;
  }

  void draw(sf::RenderTarget& target, const sf::RenderStates states) const override {
    const float time = Time::get().time();

    sf::Transform transform;
    const sf::Vector2f position = shape.getPosition();
    transform.translate({0.0f, static_cast<float>(cos(time * 2.0f + position.x * position.y)) * 10.0f});

    const float punch_time = std::clamp((time - damage_time) / 0.2f, 0.0f, 1.0f);
    const float inv_punch_time = 1.0f - punch_time;
    transform.rotate(sf::degrees(sin(2.0f * inv_punch_time * inv_punch_time * sf::priv::pi)) * 5.0f, position);

    target.draw(shape, states.transform * transform);
  }
};
