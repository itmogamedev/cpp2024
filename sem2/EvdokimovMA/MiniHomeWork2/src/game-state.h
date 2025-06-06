#pragma once

#include <iostream>
#include "cell.h"
#include "algorithm"

struct GameState {
  int health = MAX_HEALTH;
  int energy = MAX_ENERGY;

  static GameState& get() {
    static GameState instance;
    return instance;
  }

  void init_map(const sf::Vector2i& size, const int food_chance, const int enemy_chance) {
    map_size = size;
    cells    = new Cell*[size.x * size.y];

    for (unsigned int x = 0, i = 0; x < size.x; ++x) {
      for (unsigned int y = 0; y < size.y; ++y, ++i) {
        cells[i] = new Cell({x, y}, static_cast<CellType>(rand() % Cell_End));

        cells[i]->set_hidden(true);

        const bool is_food = rand() % food_chance == 0;
        cells[i]->set_food(is_food);

        if (!is_food && rand() % enemy_chance == 0) {
          auto enemy = cells[i]->enemy = new Enemy({x, y});
          enemies.push_back(enemy);
        } else {
          cells[i]->enemy = nullptr;
        }
      }
    }

    std::cout << "GameState initialized" << std::endl;
  }

  [[nodiscard]] sf::Vector2i get_map_size() const {
    return map_size;
  }
  [[nodiscard]] Cell* get_cell(const unsigned int index) const {
    return cells[index];
  }
  [[nodiscard]] Cell* get_cell(const sf::Vector2u& pos) const {
    return cells[pos.x * map_size.y + pos.y];
  }
  [[nodiscard]] Cell* get_cell(const unsigned int x, const unsigned int y) const {
    return cells[x * map_size.y + y];
  }
  [[nodiscard]] Cell** get_map() const {
    return cells;
  }
  [[nodiscard]] unsigned int get_cells_count() const {
    return map_size.x * map_size.y;
  }

  [[nodiscard]] std::vector<Enemy*> get_enemies() const {
    return enemies;
  }
  [[nodiscard]] unsigned int get_enemies_count() const {
    return enemies.size();
  }
  void destroy_enemy(Cell* cell, const Enemy* enemy) {
    if (const auto it = std::find(enemies.begin(), enemies.end(), enemy); it != enemies.end()) {
      cell->enemy = nullptr;

      delete *it;
      enemies.erase(it);
    }

    std::cout << "Enemy destroyed" << std::endl;
  }

private:
  std::vector<Enemy*> enemies;
  Cell** cells          = nullptr;
  sf::Vector2i map_size = {0, 0};
};
