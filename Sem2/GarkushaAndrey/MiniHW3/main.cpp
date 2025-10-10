#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include <ctime>

class Button {
public:
    Button(float x, float y, float width, float height, sf::Color color, const std::string& text) {
        shape.setSize(sf::Vector2f(width, height));
        shape.setPosition(x, y);
        shape.setFillColor(color);
        shape.setOutlineThickness(3);
        shape.setOutlineColor(sf::Color::Black);

        if (!font.loadFromFile("arial.ttf")) {
            buttonText.setString("");
        }
        else {
            buttonText.setFont(font);
            buttonText.setCharacterSize(24);
            buttonText.setFillColor(sf::Color::White);
            buttonText.setString(text);
            buttonText.setPosition(x + 10, y + 15);
        }
    }

    void update(sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

        if (shape.getGlobalBounds().contains(worldPos)) {
            shape.setFillColor(sf::Color(100, 0, 0));
        }
        else {
            shape.setFillColor(sf::Color::Red);
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(buttonText);
    }

    bool isClicked(sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
        return shape.getGlobalBounds().contains(worldPos);
    }

    void setFillColor(sf::Color color) {
        shape.setFillColor(color);
    }

private:
    sf::RectangleShape shape;
    sf::Text buttonText;
    sf::Font font;
};

void shutdownPC() {
    system("shutdown /s /t 0");
}

void startTimer(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    shutdownPC();
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "KILL BTN");
    window.setFramerateLimit(60);

    Button button(300, 250, 200, 80, sf::Color::Red, "Enter me...");

    bool isWaiting = false;
    int countdown = 0;
    sf::Clock timerClock;

    sf::Text countdownText;
    sf::Font font;
    if (font.loadFromFile("arial.ttf")) {
        countdownText.setFont(font);
        countdownText.setCharacterSize(30);
        countdownText.setFillColor(sf::Color::Yellow);
        countdownText.setPosition(350, 180);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (button.isClicked(window) && !isWaiting) {
                    int delay = rand() % 51 + 10;
                    countdown = delay;
                    isWaiting = true;
                    timerClock.restart();

                    std::thread t(startTimer, delay);
                    t.detach();

                    button.setFillColor(sf::Color(139, 0, 0));
                }
            }
        }

        button.update(window);

        if (isWaiting) {
            float elapsedSeconds = timerClock.getElapsedTime().asSeconds();
            int remaining = countdown - static_cast<int>(elapsedSeconds);

            if (remaining >= 0) {
                countdownText.setString("Shutdown in: " + std::to_string(remaining) + " seconds");
            }
            else {
                isWaiting = false;
                button.setFillColor(sf::Color::Red);
                countdownText.setString("");
            }
        }

        window.clear(sf::Color::Black);
        button.draw(window);
        if (isWaiting) {
            window.draw(countdownText);
        }
        window.display();
    }

    return 0;
}