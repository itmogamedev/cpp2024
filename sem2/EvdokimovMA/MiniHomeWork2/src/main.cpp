#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ctime>

#include "constants.h"
#include "time.h"
#include "game-state.h"
#include "cell.h"
#include "footer.h"

// (V) 1. M x N двумерное поле с тайлами(в примере 10 x 10)
// (V) 2. Скрытые тайлы -> открытые с эвентами
// (X) 3. эвенты должны отображаться, + Логика
// (X) 4. Под каждым тайлом с вероятность в 10% есть консервы,
// при вскрытии тайла -> восст. сытость
// (V) 5. Открыть M x N тайлов (все тайлы) для победы
// (V) 6. Экран победы + экран поражения
// (V) 7. За каждое открытие тайла теряем 1 сытость. Сытость равно 0,
// тогда поражение, + отображать сытость
// (X) 8. Начальное значени сытости - 25

bool isWinOfGame() {
	const GameState& game_state = GameState::get();
	Cell** cells = game_state.get_map();
	const unsigned int size = game_state.get_cells_count();

	bool winCondition = true;
	for (unsigned int i = 0; i < size; ++i) {
		if (cells[i]->is_hidden() || cells[i]->has_enemy()) {
			winCondition = false;
			break;
		}
	}

	return winCondition;
}
bool isLoseOfGame() {
	const GameState& game_state = GameState::get();
	return game_state.energy <= 0 || game_state.health <= 0;
}

void clickTile(const sf::Vector2f &mouseCoord) {
	GameState& game_state = GameState::get();
	const sf::Vector2i map_size = game_state.get_map_size();

	const auto x = static_cast<unsigned int>(mouseCoord.x / CELL_SIZE_SCREEN);
	const auto y = static_cast<unsigned int>(mouseCoord.y / CELL_SIZE_SCREEN);

	if (x >= map_size.x || y >= map_size.y) {
		return;
	}

	Cell* cell = game_state.get_cell(x, y);

	if (cell->is_hidden()) {
		cell->set_hidden(false);
		game_state.energy--;

		// Get reward for opening cell
		if (!cell->has_enemy() && cell->is_food()) {
			game_state.energy = MAX_ENERGY;
		}

		return;
	}

	if (cell->has_enemy()) {
		game_state.energy--;
		if (!cell->enemy->hit()) {
			if (rand() % 10 == ENEMY_DAMAGE_CHANCE) {
				game_state.health -= (rand() % (ENEMY_DAMAGE_MAX - ENEMY_DAMAGE_MIN + 1)) + ENEMY_DAMAGE_MIN;
			}

			return;
		}

		game_state.destroy_enemy(cell, cell->enemy);

		// Get reward for killing enemy
		if (cell->is_food()) {
			game_state.energy = MAX_ENERGY;
		}
	}
}

int main() {
	srand(time(nullptr));

	GameState& game_state = GameState::get();
	game_state.init_map({MAP_SIZE_M, MAP_SIZE_N}, FOOD_CHANCE, ENEMY_CHANCE);

	sf::RenderWindow window(
		sf::VideoMode({
			static_cast<unsigned int>(CELL_SIZE_SCREEN * MAP_SIZE_M),
			static_cast<unsigned int>(CELL_SIZE_SCREEN * MAP_SIZE_N) + FOOTER_HEIGHT
		}),
		"NOT MINESWEEPER GAME", sf::State::Windowed);

	const sf::Font font("assets/arial.ttf");
	Footer footer(font);

	sf::Text text_condition(font);
	text_condition.setCharacterSize(CELL_SIZE_SCREEN);
	text_condition.setStyle(sf::Text::Bold);
	text_condition.setOutlineThickness(10);
	text_condition.setFillColor({231, 76, 60});
	text_condition.setOutlineColor({0, 0, 0});

	bool mouse_pressed = false;
	sf::Clock delta_clock;
	Time &time_manager = Time::get();

	bool is_game_win = false;
	bool is_game_lose = false;

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();

			if (const auto* key_pressed = event->getIf<sf::Event::KeyPressed>()) {
				if (key_pressed->scancode == sf::Keyboard::Scancode::Escape)
					window.close();
			}

			if (!isButtonPressed(sf::Mouse::Button::Left)) {
				mouse_pressed = false;
			}

			if (!mouse_pressed && isButtonPressed(sf::Mouse::Button::Left) && !is_game_win && !is_game_lose) {
				mouse_pressed = true;
				auto mouse_coord   = window.mapPixelToCoords(sf::Mouse::getPosition(window));

				clickTile(mouse_coord);
				footer.update(window);

				is_game_win = isWinOfGame();
				is_game_lose = isLoseOfGame();

				if (is_game_win) {
					text_condition.setString("WINNER");
				} else if (is_game_lose) {
					text_condition.setString("LOSER");
				} else {
					text_condition.setString("");
				}

				text_condition.setPosition(
					{(window.getSize().x - text_condition.getGlobalBounds().size.x) / 2,
					 (CELL_SIZE_SCREEN * MAP_SIZE_N / 2.0f) - text_condition.getGlobalBounds().size.y / 2});
			}
		}

		window.clear();
		time_manager.update(delta_clock.restart().asSeconds());

		Cell** cells = game_state.get_map();
		const unsigned int size = game_state.get_cells_count();
		for (unsigned int i = 0; i < size; ++i) {
			window.draw(*cells[i]);
		}

		window.draw(footer);
		if (is_game_win || is_game_lose) {
			window.draw(text_condition);
		}

		window.display();
	}
}