#pragma once
#ifndef GAME
#define GAME

#include "Randomizer.h"
#include "SFMLExtention.h"
#include <vector>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>

constexpr unsigned int SCREEN_W = 500, SCREEN_H = 500;
constexpr int CELL_COUNT = 9, CELL_SIZE = 40.0f;
constexpr int CHANCE_FOOD = 10, CHANCE_ENEMY = 5;

enum GameState
{
	Play, Lose, Win
};

class Game
{
public:
	Game();
	~Game() = default;
	void init();
	void check(sf::RenderWindow& window);
	void draw(sf::RenderTarget& window);
private:
	sf::Font font;
	int playerEnregy;
	int playerHP;
	int openedCell = 0;
	GameState state;
	std::vector<std::unique_ptr<FlipButton>> cells;
	std::vector<sf::Texture> textures;

	void loadText();
	void checkState();
};

#endif // !GAME