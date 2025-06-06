#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
#include <ctime>
#include <chrono>
#include <thread>
#include <random>
#include <cstdlib> // для system()


void random_delay(int min_ms, int max_ms) {
    // Генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min_ms, max_ms);

    // Получаем случайное время задержки
    int delay_ms = distr(gen);

    // Задержка
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
}
int main() {

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Turn off");

    bool mousepressed = false;
    sf::Vector2i mouseCoord;
    int n = 10000;
    int m = 60000;

    sf::RectangleShape button({ 200, 80 });
    button.setPosition({ 300, 260 });
    button.setFillColor(sf::Color::Red);



    sf::Font font("arial.ttf");
    sf::Text textEnergy(font);
    textEnergy.setString("Turn off");
    textEnergy.setPosition({ 350, 280 });
    textEnergy.setFillColor(sf::Color::White);


    while (window.isOpen()) {
        
            while (const std::optional event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>())
                    window.close();
        
                if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                    if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                        window.close();
                }
                if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    mousepressed = false;
                }
                
                if (!mousepressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    mousepressed = true;
                    mouseCoord = sf::Mouse::getPosition(window);
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x),
                        static_cast<float>(mousePos.y));

                    if (button.getGlobalBounds().contains(mousePosF)) {
#ifdef _WIN32
                        random_delay(n, m);
                        std::system("shutdown /s /t 0"); // Windows
#else
                        random_delay(n, m);
                        std::system("shutdown now"); // Linux/macOS (требует sudo)
#endif


                }
            }
        }

        // Отрисовка
        window.clear(sf::Color::Black);
        window.draw(button);
        window.draw(textEnergy);
        window.display();
    }

   return 0;
}