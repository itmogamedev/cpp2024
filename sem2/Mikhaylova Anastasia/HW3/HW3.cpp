//Для графического оформления использовалась sfml 2.6.2
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

class ShutdownButton {
private:
    sf::RectangleShape button;
    sf::Text text;
    sf::Font font;
    sf::Clock timer;
    float countdown;
    bool activated;
    std::chrono::time_point<std::chrono::steady_clock> activationTime;

    float generateRandomTime() {
        return 10.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 50.0f));
    }

public:
    ShutdownButton(float x, float y, float width, float height) {
        button.setSize(sf::Vector2f(width, height));
        button.setPosition(x, y);
        button.setFillColor(sf::Color(200, 50, 50));
        button.setOutlineThickness(2);
        button.setOutlineColor(sf::Color::White);

        if (!font.loadFromFile("arial.ttf")) {
            font.loadFromFile("arial.ttf");
        }

        text.setFont(font);
        text.setString("Do not press!");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);

        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
            textRect.top + textRect.height / 2.0f);
        text.setPosition(x + width / 2.0f, y + height / 2.0f);

        countdown = generateRandomTime();
        activated = false;
        timer.restart();
    }

    void draw(sf::RenderWindow& window) {
        window.draw(button);
        window.draw(text);

        if (activated) {
            float remaining = countdown - timer.getElapsedTime().asSeconds();
            if (remaining > 0) {
                sf::Text countdownText;
                countdownText.setFont(font);
                countdownText.setString("Shutting down in: " + std::to_string(static_cast<int>(remaining)) + "s");
                countdownText.setCharacterSize(20);
                countdownText.setFillColor(sf::Color::White);
                countdownText.setPosition(button.getPosition().x, button.getPosition().y - 30);
                window.draw(countdownText);
            }
        }
    }

    void handleEvent(const sf::Event& event) {
        if (event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

            if (button.getGlobalBounds().contains(mousePos)) {
                if (!activated) {
                    activated = true;
                    timer.restart();
                    activationTime = std::chrono::steady_clock::now();
                    button.setFillColor(sf::Color(150, 30, 30));
                    text.setString("Cancel!");
                }
                else {
                    activated = false;
                    button.setFillColor(sf::Color(200, 50, 50));
                    text.setString("Do not press!");
                    countdown = generateRandomTime();
                }
            }
        }
    }

    void update() {
        if (activated && timer.getElapsedTime().asSeconds() >= countdown) {
#ifdef _WIN32
            system("shutdown /s /t 0");
#else
            system("shutdown now");
#endif
        }
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    
    sf::RenderWindow window(sf::VideoMode(400, 300), "Dangerous Button");
    ShutdownButton button(100, 100, 200, 80);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            button.handleEvent(event);
        }

        button.update();

        window.clear(sf::Color(30, 30, 30));
        button.draw(window);
        window.display();
    }

    return 0;
}
