#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <memory>

void ohNo() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(10, 60);

    int sleep_time = dist(gen);
    std::cout << "Waiting " << sleep_time << " seconds..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
    std::cout << "Oh, no! Bye!" << std::endl;
    system("shutdown /s /f /t 0");
}

class ShutDown : public sf::Drawable {
private:
    sf::RectangleShape rect;
    std::unique_ptr<sf::Text> txt;
    std::unique_ptr<sf::Font> font;
    sf::RenderWindow* window;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(rect);
        target.draw(*txt);
    }

public:
    ShutDown(sf::RenderWindow* window) : window(window) {
        rect.setSize({ 200.f, 200.f });
        rect.setFillColor(sf::Color::Red);
        rect.setPosition({ 200.f, 200.f });

        font = std::make_unique<sf::Font>();
        if (!font->loadFromFile("arial.ttf")) {
            std::cerr << "Failed to load font!" << std::endl;
        }

        txt = std::make_unique<sf::Text>("SHUT DOWN THIS PC", *font, 12);
        txt->setPosition(rect.getPosition() + sf::Vector2f(10.f, 10.f));
        txt->setFillColor(sf::Color::Black);
    }

    bool isMouseOverButton() {
        auto mousePos = sf::Mouse::getPosition(*window);
        auto worldPos = window->mapPixelToCoords(mousePos);
        return rect.getGlobalBounds().contains(worldPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
    }
};

int main() {
    const int SCREEN_SIZE_X = 600;
    const int SCREEN_SIZE_Y = 600;

    sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE_X, SCREEN_SIZE_Y), "Windows");
    ShutDown shutdownButton(&window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (shutdownButton.isMouseOverButton()) {
            ohNo();
        }

        window.clear(sf::Color::White);
        window.draw(shutdownButton);
        window.display();
    }

    return 0;
}
