// miniHW_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ctime>

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

#define CELLSIZE_M 10
#define CELLSIZE_N 10

#define CHANCE_FOOD 10
#define CHANCE_ENEMY 10

#define ENERGY_MAX 50
#define HP_MAX   100

#define CELLSIZE_SCREEN 100.f

enum CellType {
    Type_enemy,
    Type_Grass,
    Type_Hill,
    Type_Forest,
    Type_Stone,
    Type_Sand,
    Type_Snow,
    Type_Water,
    Type_End
};
enum TextureType {
    Texture_Enemy,
    Texture_Grass,
    Texture_Hill,
    Texture_Forest,
    Texture_Stone,
    Texture_Sand,
    Texture_Snow,
    Texture_Water,
    Texture_Hide,
    Texture_Soup,
    Texture_End
};

struct Cell {
    bool isEnemy;
    bool isHidden;
    bool isFood;
    CellType cellType;
};

bool isWinOfGame(const Cell cells[CELLSIZE_M][CELLSIZE_N]) {
    bool winCondition = true;
    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            if (cells[x][y].isHidden) {
                winCondition = false;
                break;
            }
        }
    }
    return winCondition;
}

bool isLoseOfGame(const int& energy, const int& hp) {
    if (energy <= 0 or hp <= 0) {
        return true;
    }
    return false;
}

void clickTile(int& energy,int& hp,
    const sf::Vector2i& mouseCoord,
    Cell cells[CELLSIZE_M][CELLSIZE_N],
    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N],
    sf::Texture textures[TextureType::Texture_End]) {

    const int x = mouseCoord.x < 0 ?
        0 :
        mouseCoord.x > CELLSIZE_SCREEN * CELLSIZE_M ?
        CELLSIZE_M :
        mouseCoord.x / CELLSIZE_SCREEN;

    const int y = mouseCoord.y < 0 ?
        0 :
        mouseCoord.y > CELLSIZE_SCREEN * CELLSIZE_N ?
        CELLSIZE_N :
        mouseCoord.y / CELLSIZE_SCREEN;

    cells[x][y].isHidden = false;

    if (cells[x][y].isFood) {
        shapes[x][y].setTexture(&textures[TextureType::Texture_Soup]);
        energy = ENERGY_MAX;
    }
    else if (cells[x][y].isEnemy) {
        shapes[x][y].setTexture(&textures[TextureType::Texture_Enemy]);
        hp -= 10;
    }
    else
        shapes[x][y].setTexture(&textures[cells[x][y].cellType]);
}

int main() {
    int energy = ENERGY_MAX;
    int hp = HP_MAX;

    srand(time(0));

    Cell cells[CELLSIZE_M][CELLSIZE_N];
    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            cells[x][y].isHidden = true;
            cells[x][y].isFood = rand() % 100 < CHANCE_FOOD;
            cells[x][y].isEnemy = rand() % 100 < CHANCE_ENEMY;
            cells[x][y].cellType = static_cast<CellType>
                (rand() % (CellType::Type_End - 1));
        }
    }

    sf::RenderWindow window(
        sf::VideoMode({ static_cast <unsigned int> (CELLSIZE_SCREEN * CELLSIZE_M),
            static_cast <unsigned int> (CELLSIZE_SCREEN * CELLSIZE_N) }),
        "NOT MINESWEEPER GAME", sf::State::Windowed);
    sf::Vector2i mouseCoord;

    sf::Font font("arial.ttf");
    sf::Text textEnergy(font);
    sf::Text textCondition(font);
    sf::Text textHp(font);
    textEnergy.setCharacterSize(CELLSIZE_SCREEN / 2);
    textEnergy.setFillColor(sf::Color::Red);
    textEnergy.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textCondition.setCharacterSize(CELLSIZE_SCREEN);
    textCondition.setFillColor(sf::Color::Red);
    textCondition.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textHp.setCharacterSize(CELLSIZE_SCREEN / 2);
    textHp.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textHp.setFillColor(sf::Color::Green);
    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N];
    sf::Texture textures[TextureType::Texture_End];
    textures[TextureType::Texture_Enemy] = sf::Texture("enemy.png");
    textures[TextureType::Texture_Grass] = sf::Texture("grass.png");
    textures[TextureType::Texture_Hill] = sf::Texture("hill.png");
    textures[TextureType::Texture_Forest] = sf::Texture("forest.png");
    textures[TextureType::Texture_Stone] = sf::Texture("stone.png");
    textures[TextureType::Texture_Sand] = sf::Texture("sand.png");
    textures[TextureType::Texture_Snow] = sf::Texture("snow.png");
    textures[TextureType::Texture_Water] = sf::Texture("water.png");
    textures[TextureType::Texture_Hide] = sf::Texture("hide.png");
    textures[TextureType::Texture_Soup] = sf::Texture("soup.png");


    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {

            // TODO функцию а не напрямую
            if (cells[x][y].isHidden)
                shapes[x][y].setTexture(&textures[TextureType::Texture_Hide]);
            else
                shapes[x][y].setTexture(&textures[cells[x][y].cellType]);

            shapes[x][y].setPosition(
                sf::Vector2f(x * CELLSIZE_SCREEN, y * CELLSIZE_SCREEN));
            shapes[x][y].setSize({ CELLSIZE_SCREEN, CELLSIZE_SCREEN });
        }
    }

    bool mousepressed = false;
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

                clickTile(energy, hp, mouseCoord, cells, shapes, textures);
                energy--;
                textEnergy.setString(std::to_wstring(energy));
                textHp.setString(L"\n" + std::to_wstring(hp));

                if (isWinOfGame(cells))
                    textCondition.setString("WINNER!!!");
                if (isLoseOfGame(energy, hp))
                    textCondition.setString("LOSER!!!");
            }
        }

        window.clear();
        for (int x = 0; x < CELLSIZE_M; x++) {
            for (int y = 0; y < CELLSIZE_N; y++) {
                window.draw(shapes[x][y]);
            }
        }
        window.draw(textHp);
        window.draw(textEnergy);
        window.draw(textCondition);
        window.display();
    }
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
