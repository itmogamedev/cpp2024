#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ctime>
#include "GameController.h"

// (V) 1. M x N двумерное поле с тайлами(в примере 10 x 10)
// (V) 2. Скрытые тайлы -> открытые с эвентами
// (X) 3. эвенты должны отображаться, + Логика
// (X) 4. Под каждым тайлом с вероятность в 10% есть консервы,
// при вскрытии тайла -> восст. сытость
// (V) 5. Открыть M x N тайлов (все тайлы) для победы
// (V) 6. Экран победы + экран поражения
// (V) 7. За каждое открытие тайла теряем 1 сытость. Сытость равно 0,
// тогда поражение, + отображать сытость
// (V) 8. Начальное значени сытости - 25


sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N];
sf::Texture textures[TextureType::Texture_End];

void mainCycle (GameController & ctrl, sf::RenderWindow & window) {

    bool mousepressed = false;
    sf::Vector2i mouseCoord;
    int tileX = 0, tileY = 0;

    sf::Font font("arial.ttf");
    sf::Text textEnergy(font);
    sf::Text textCondition(font);
    textEnergy.setCharacterSize(CELLSIZE_SCREEN / 2);
    textEnergy.setFillColor(sf::Color::Red);
    textEnergy.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textCondition.setCharacterSize(CELLSIZE_SCREEN);
    textCondition.setFillColor(sf::Color::Red);
    textCondition.setStyle(sf::Text::Bold | sf::Text::Underlined);

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

                ctrl.clickTile(mouseCoord.x, mouseCoord.y, tileX, tileY);

                if (ctrl.isFood(tileX, tileY)) {
                    shapes[tileX][tileY].setTexture(&textures[TextureType::Texture_Soup]);
                }
                else
                    shapes[tileX][tileY].setTexture(&textures[ctrl.getCellType(tileX, tileY)]);

                textEnergy.setString(std::to_wstring(ctrl.getEnergy()));

                if (ctrl.isWinOfGame())
                    textCondition.setString("WINNER!!!");
                if (ctrl.isLoseOfGame())
                    textCondition.setString("LOSER!!!");
            }
        }

        window.clear();
        for (int x = 0; x < CELLSIZE_M; x++) {
            for (int y = 0; y < CELLSIZE_N; y++) {
                window.draw(shapes[x][y]);
            }
        }
        window.draw(textEnergy);
        window.draw(textCondition);
        window.display();
    } 
}


int main() {
    srand(time(0));

    sf::RenderWindow window(
        sf::VideoMode({ static_cast <unsigned int> (CELLSIZE_SCREEN * CELLSIZE_M),
            static_cast <unsigned int> (CELLSIZE_SCREEN * CELLSIZE_N) }),
        "NOT MINESWEEPER GAME", sf::State::Windowed);

    for (int i = 0; i < TextureType::Texture_End; i++)
        textures[i].loadFromFile(textureFiles[i] + ".png");

    GameController ctrl;
    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {

            shapes[x][y].setTexture(&textures[
               ctrl.isHidden(x, y) ?
                  TextureType::Texture_Hide :
                  ctrl.getCellType(x, y)
                ]);

            shapes[x][y].setPosition(
                sf::Vector2f(x * CELLSIZE_SCREEN, y * CELLSIZE_SCREEN));
            shapes[x][y].setSize({ CELLSIZE_SCREEN, CELLSIZE_SCREEN });
        }
    }

    mainCycle(ctrl, window);
}
