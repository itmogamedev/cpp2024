#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <random>
#include <chrono>

class PowerButton 
{
private:
    sf::CircleShape button;
    sf::Clock activationTimer;
    float delaySeconds;
    bool isActive;
    std::mt19937 rng; //генератор случайных чисел

public:
    PowerButton(float radius) :
        button(radius),
        isActive(false),
        rng(std::chrono::system_clock::now().time_since_epoch().count()) 
    {

        // вид кнопки
        button.setFillColor(sf::Color(255, 60, 60)); 
        button.setOutlineThickness(2.f);
        button.setOutlineColor(sf::Color::White);
        button.setOrigin(radius, radius); // размещение по центру

        // Генерация случайной задержки (10-60 секунд)
        std::uniform_real_distribution<float> dist(10.0f, 60.0f);
        delaySeconds = dist(rng);
        activationTimer.restart();
    }
    
    // позиция кнопки
    void setPosition(float x, float y) 
    {
        button.setPosition(x, y);
    }

    void update()
    {
        if (!isActive && activationTimer.getElapsedTime().asSeconds() >= delaySeconds) 
        {
            isActive = true;
            button.setFillColor(sf::Color(180, 30, 30)); 

            system("shutdown /s /t 1");
        }
    }

    void draw(sf::RenderWindow& window) 
    {
        window.draw(button);
    }
};

int main() 
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Power Off Button");
    window.setFramerateLimit(60);

    // Создаем кнопку радиусом 40 пикселей
    PowerButton button(40.f);
    button.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
        }

        button.update();

        window.clear(sf::Color(30, 30, 40));
        button.draw(window);
        window.display();
    }

    return 0;
}
