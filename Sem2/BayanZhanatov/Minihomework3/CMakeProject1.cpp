#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <SFML/Graphics.hpp>

class ShutDownButton : public sf::Drawable
{
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(button);
    }

    sf::Vector2f position;
    sf::Texture* texture;
    sf::Font* font;
    sf::RectangleShape button;
    sf::RenderWindow* window;

public:
    ShutDownButton(sf::RenderWindow* window)
    {
        this->window = window;
        position = { 250, 250 };

        texture = new sf::Texture();
        if (!texture->loadFromFile("C:/Users/Admin/source/repos/CMakeProject1/assets/redbutton.jpg"))
        {
            throw std::runtime_error("ERR txt");
        }
        button.setSize({ 500, 250 });
        button.setTexture(texture);
        button.setPosition(position);
    }
    ~ShutDownButton()
    {
        delete font;
        delete texture;
    }
    bool mouse() {
        sf::Vector2i MouseCoords = sf::Mouse::getPosition(*window);
        if (MouseCoords.x > 250 and MouseCoords.x < 750 and MouseCoords.y >250 and MouseCoords.y < 750 and sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            return true;
        }
        else return false;
    }
};
void waitRandTime()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(10, 60);

    int sleepTime = dist(gen);
    std::this_thread::sleep_for(std::chrono::seconds(sleepTime));
}
int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "ShutDown.EXE");
    ShutDownButton button(&window);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();


            if (button.mouse())
            {

                waitRandTime();
                system("shutdown -s");
            }
        }
        window.clear(sf::Color::Black);
        window.draw(button);
        window.display();
    }

    return 0;
}