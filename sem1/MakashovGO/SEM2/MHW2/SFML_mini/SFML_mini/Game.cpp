#include "Game.h"

Game::Game()
{
	state = Play;
	cells = std::vector < std::unique_ptr<FlipButton>>();
	playerEnregy = 25;
	playerHP = 5;
}

void Game::init()
{
	loadText();
	sf::RectangleShape baseShape({CELL_SIZE, CELL_SIZE});
	FlipButton button(baseShape);
	for (int x = 0, y = 0; x < CELL_COUNT * CELL_COUNT; x++, y++)
	{
		button.setPosition({ (x % CELL_COUNT) * (CELL_SIZE + 0.75f), (y / CELL_COUNT) * (0.75f + CELL_SIZE) });

		if (1.0f / CHANCE_FOOD > Random::bitRandom())
		{
			button.setTexture(textures[0], textures[1]);
			button.setFunc([&]() { playerEnregy += 5; });
		}
		else if (1.0f / CHANCE_ENEMY > Random::bitRandom())
		{
			button.setTexture(textures[0], textures[2]);
			button.setFunc([&]() { playerHP--; playerEnregy--; });
		}
		else
		{
			button.setTexture(textures[0], textures[Random::intRandom(3, textures.size() - 1)]);
			button.setFunc([&]() { playerEnregy--; });
		}



		cells.push_back(std::make_unique<FlipButton>(button));
	}
}

void Game::loadText()
{
	textures = std::vector<sf::Texture>();
	std::string baseName = "Texture/texture";
	int i = 1;
	while (true)
	{
		std::string tempName = baseName + std::to_string(i) + ".png";
		sf::Texture text;
		if (!text.loadFromFile(tempName)) break;
		textures.push_back(text);
		i++;
	}
	if (!font.loadFromFile("Texture/Arial.ttf")) return;
}



void Game::check(sf::RenderWindow& window)
{
	if (playerEnregy <= 0) return;

	sf::Vector2i mouse = sf::Mouse::getPosition(window);
	sf::Vector2f worldPos = window.mapPixelToCoords(mouse);

	for (int i = 0; i < cells.size(); i++)
	{
		if (cells[i]->isClick(worldPos))
		{
			cells[i]->use();
			openedCell++;
			checkState();
			break;
		}
	}
}

void Game::checkState()
{
	if (playerHP <= 0 || playerEnregy <= 0)
	{
		state = Lose;
	}
	else if (openedCell >= cells.size()/2.0f)
	{
		state = Win;
	}
}

void Game::draw(sf::RenderTarget& window)
{
	if (state == Lose) 
	{
		sf::Text text;
		text.setCharacterSize(70);
		text.setFillColor(sf::Color::Red);
		text.setFont(font);
		text.setString("You Lose");
		auto bound = text.getLocalBounds();
		text.setOrigin({ bound.left + bound.width / 2, bound.top + bound.height / 2 });
		text.setPosition({ SCREEN_W / 2.0f, SCREEN_H / 2.0f });
		window.draw(text);
	}
	else if (state == Win)
	{
		sf::Text text;
		text.setCharacterSize(70);
		text.setFillColor(sf::Color::Green);
		text.setFont(font);
		text.setString("You Win");
		auto bound = text.getLocalBounds();
		text.setOrigin({ bound.left + bound.width / 2, bound.top + bound.height / 2 });
		text.setPosition({ SCREEN_W / 2.0f, SCREEN_H / 2.0f });
		window.draw(text);
	}
	else if (state == Play)
	{
		for (auto cell = cells.begin(); cell < cells.end(); cell++)
		{
			window.draw(*cell->get());
		}

		sf::Text text(std::to_string(playerEnregy), font, 40);
		text.setFillColor(sf::Color::Green);
		auto bound = text.getLocalBounds();
		text.setOrigin({ bound.left + bound.width / 2, bound.top + bound.height / 2 });
		text.setPosition({ CELL_COUNT * CELL_SIZE + 5.0f, 40.0f });
		window.draw(text);

		text.setFillColor(sf::Color::Red);
		text.setString(std::to_string(playerHP));
		text.move({ 0,40.0f });
		window.draw(text);
	}
}