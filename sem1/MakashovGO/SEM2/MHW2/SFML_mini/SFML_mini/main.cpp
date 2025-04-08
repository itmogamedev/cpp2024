#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow window({SCREEN_W, SCREEN_H}, "GAME");
	Game game{};
	game.init();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.mouseButton.button == sf::Mouse::Left && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				game.check(window);
			}
		}

		window.clear();

		game.draw(window);

		window.display();
	}
	return 0;
}