#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <windows.h>
#include <optional>

void shutdownPC() {
    system("shutdown /s /t 0");
}

void handleEvents(sf::RenderWindow& window, sf::Sprite& buttonSprite, sf::Texture& buttonTextureNormal, sf::Texture& buttonTextureClicked, int delay, bool& buttonClicked) {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
        else if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
        {
            if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePos);

                if (buttonSprite.getGlobalBounds().contains(mouseWorldPos)) {
                    
                    buttonSprite.setTexture(buttonTextureClicked);
                    buttonClicked = true; 

                    std::cout << "Button clicked! Delaying shutdown by " << delay << " seconds." << std::endl;
                    std::thread shutdownThread([delay]() {
                        std::this_thread::sleep_for(std::chrono::seconds(delay));
                        shutdownPC();
                        });
                    shutdownThread.detach();
                }
            }
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                window.close();
            }
        }
    }
}

void render(sf::RenderWindow& window, sf::Sprite& buttonSprite) {
    window.clear(sf::Color::Black);
    window.draw(buttonSprite);
    window.display();
}

int main() {
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

   
    sf::RenderWindow window(sf::VideoMode({ 440, 300 }), "Shutdown Button");
    window.setFramerateLimit(60);

    
    sf::Texture buttonTextureNormal;
    if (!buttonTextureNormal.loadFromFile("button1.png")) {
        std::cerr << "Error loading button_normal.png" << std::endl;
        return -1;
    }

    sf::Texture buttonTextureClicked;
    if (!buttonTextureClicked.loadFromFile("button2.png")) {
        std::cerr << "Error loading button_clicked.png" << std::endl;
        return -1;
    }

    
    sf::Sprite buttonSprite(buttonTextureNormal);
    buttonSprite.setPosition({ 100, 75 });

    
    bool buttonClicked = false;

    
    while (window.isOpen()) {
        int delay = 10 + std::rand() % 91; 
        handleEvents(window, buttonSprite, buttonTextureNormal, buttonTextureClicked, delay, buttonClicked);
        render(window, buttonSprite);
    }

    std::cout << "Exiting program." << std::endl;
    return 0;
}