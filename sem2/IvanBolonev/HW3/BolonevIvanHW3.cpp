#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <cstdlib> 

void randomDelay() {
    
    std::random_device rd;  // Рандомним число
    std::mt19937 gen(rd());  // Инициализируем генератор
    std::uniform_int_distribution<> dis(1, 60); // Диапазон от 10 до 60 секунд


    int delayTime = dis(gen);


    std::this_thread::sleep_for(std::chrono::seconds(delayTime));
}

void turn_off()
{
    randomDelay();
    //std::cout << "Конец компу" << std::endl;
    system("shutdown -s");
}

int main() {
    setlocale(LC_ALL, "Russiаn");
    system("chcp 1251");
    // Создаем окно 
    sf::RenderWindow window(sf::VideoMode(770, 671), "DO NOT PRESS THE BUTTON");
    // Создаем кнопку с картинкой
    sf::Texture buttonTexture;
    if (!buttonTexture.loadFromFile("delovoe-predlozhenie-mem.png")) {
        std::cerr << "Ошибка!" << std::endl;
        return -1;
    }
    sf::Sprite buttonSprite;
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(0, 0);

    //Главный цикл
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
        
            if (event.type == sf::Event::Closed)
                window.close();

        
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
        
                    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
        
                    //Нажимаем на кнопку - вызываем краш компа
                    if (buttonSprite.getGlobalBounds().contains(mousePos)) {
                        turn_off();
                        std::cout << "Button clicked!" << std::endl;
                    }
                }
            }
        }


        window.clear(sf::Color::Black);
        window.draw(buttonSprite);
        window.display();
    }

    return 0;
}