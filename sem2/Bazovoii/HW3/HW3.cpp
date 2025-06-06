#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <windows.h> 

int main() {
    srand(time(0)); 

    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shutdown Timer");
    window.setFramerateLimit(60);

    
    sf::Font font;
    font.loadFromFile("arial.ttf");

    
    sf::Text countdownText("", font, 50);
    countdownText.setPosition(300, 100);
    countdownText.setFillColor(sf::Color::White);

    
    sf::RectangleShape button(sf::Vector2f(300, 100));
    button.setPosition(250, 300);
    button.setFillColor(sf::Color(70, 130, 180)); // SteelBlue
    button.setOutlineThickness(2);
    button.setOutlineColor(sf::Color::White);

    sf::Text buttonText("Click for timer", font, 30);
    buttonText.setPosition(310, 330);
    buttonText.setFillColor(sf::Color::White);

   
    bool isCounting = false;
    int totalSeconds = 0;
    sf::Clock timer;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            
            if (event.type == sf::Event::MouseButtonPressed && !isCounting) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    totalSeconds = 10 + rand() % 51; // 10-60 сек
                    isCounting = true;
                    timer.restart();
                }
            }
        }

       
        if (isCounting) {
            int remaining = totalSeconds - timer.getElapsedTime().asSeconds();

            if (remaining <= 0) {
                countdownText.setString("Abeba...");
                window.draw(countdownText);
                window.display();
                Sleep(1000);
                system("shutdown /s /t 0");
                window.close();
            }
            else {
                countdownText.setString("Until turning off: " + std::to_string(remaining) + " sec.");
            }
        }

        
        window.clear(sf::Color(30, 30, 30)); 

        if (!isCounting) {
            window.draw(button);
            window.draw(buttonText);
        }

        window.draw(countdownText);
        window.display();
    }

    return 0;
}