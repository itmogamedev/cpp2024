#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

int main() {
    sf::RenderWindow window(sf::VideoMode({ 400, 200 }), "Shutdown Button");

    sf::RectangleShape button(sf::Vector2f(300.f, 100.f));
    button.setPosition({ 50.f, 50.f });
    button.setFillColor(sf::Color(100, 200, 150));

    sf::Font font;
    if (!font.openFromFile("arial.ttf")) return 1;

    sf::Text text(font, "DO NOT PRESS", 30);
    text.setFont(font);
    text.setString("DO NOT PRESS");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setPosition({ 100.f, 85.f });

    sf::Texture texture;
    if (!texture.loadFromFile("boykisser.png")) return 2;
    sf::Sprite sprite(texture);
    sprite.setPosition({ 50.f, 50.f });
    sprite.setScale(sf::Vector2f(
        300.f / texture.getSize().x,
        100.f / texture.getSize().y
    ));

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    const float delay = 10.f + static_cast<float>(std::rand() % 51);
    sf::Clock timer;

    bool pressed = false;

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (auto mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseEvent->button == sf::Mouse::Button::Left) {
                    sf::Vector2f mousePos(static_cast<float>(mouseEvent->position.x), static_cast<float>(mouseEvent->position.y));
                    if (button.getGlobalBounds().contains(mousePos)) {
                        pressed = true;
                    }
                }
            }
        }

        if (pressed && timer.getElapsedTime().asSeconds() >= delay) {
#ifdef _WIN32
            std::system("shutdown /s /t 0");
#else
            std::system("shutdown now");
#endif
            window.close();
        }

        window.clear(sf::Color::White);
        window.draw(button);
        window.draw(sprite);
        window.draw(text);
        window.display();
    }

    return 0;
}
