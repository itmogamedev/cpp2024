#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ctime>
#include <algorithm>

#define CELLSIZE_M 10
#define CELLSIZE_N 10
#define CHANCE_FOOD 10
#define ENERGY_MAX 100
#define CELLSIZE_SCREEN 100.f
#define HEALTH_POINT_DECREASE_1 20  // Снижение здоровья при открытии клетки с первым типом врага
#define HEALTH_POINT_DECREASE_2 30  // Снижение здоровья при открытии клетки с вторым типом врага
#define HUNGER_DECREASE 5  // Снижение голода при открытии любой клетки

enum CellType {
    Type_Grass,
    Type_Hill,
    Type_Forest,
    Type_Stone,
    Type_Sand,
    Type_Snow,
    Type_Water,
    Type_Enemy1,  // Первый тип врага (с уменьшением здоровья на 20)
    Type_Enemy2,  // Второй тип врага (с уменьшением здоровья на 30)
    Type_End
};

enum TextureType {
    Texture_Grass,
    Texture_Hill,
    Texture_Forest,
    Texture_Stone,
    Texture_Sand,
    Texture_Snow,
    Texture_Water,
    Texture_Hide,
    Texture_Soup,
    Texture_Enemy1,  // Текстура для первого врага
    Texture_Enemy2,  // Текстура для второго врага
    Texture_End
};

struct Cell {
    bool isHidden;
    bool isFood;
    CellType cellType;
};

bool isWinOfGame(const Cell cells[CELLSIZE_M][CELLSIZE_N]) {
    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            if (cells[x][y].isHidden) {
                return false;
            }
        }
    }
    return true;
}

bool isLoseOfGame(const int& healthPoint) {
    return healthPoint <= 0;
}

bool isLoseOfHunger(const int& hunger) {
    return hunger <= 0;
}

void clickTile(int& healthPoint, int& hunger,
    const sf::Vector2i& mouseCoord,
    Cell cells[CELLSIZE_M][CELLSIZE_N],
    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N],
    sf::Texture textures[TextureType::Texture_End]) {

    int x = std::max(0, std::min(mouseCoord.x / static_cast<int>(CELLSIZE_SCREEN), CELLSIZE_M - 1));
    int y = std::max(0, std::min(mouseCoord.y / static_cast<int>(CELLSIZE_SCREEN), CELLSIZE_N - 1));

    cells[x][y].isHidden = false;

    if (cells[x][y].isFood) {
        shapes[x][y].setTexture(&textures[TextureType::Texture_Soup]);
        healthPoint = ENERGY_MAX;
        hunger = 100;  // Сбросить голод
    }
    else if (cells[x][y].cellType == Type_Enemy1) {
        shapes[x][y].setTexture(&textures[TextureType::Texture_Enemy1]);
        healthPoint -= HEALTH_POINT_DECREASE_1;  // Уменьшаем здоровье на 20
    }
    else if (cells[x][y].cellType == Type_Enemy2) {
        shapes[x][y].setTexture(&textures[TextureType::Texture_Enemy2]);
        healthPoint -= HEALTH_POINT_DECREASE_2;  // Уменьшаем здоровье на 30
    }
    else {
        shapes[x][y].setTexture(&textures[cells[x][y].cellType]);
        hunger -= HUNGER_DECREASE;  // Уменьшаем голод
    }
}

int main() {
    int healthPoint = ENERGY_MAX;
    int hunger = 100;  // Начальный уровень голода
    bool gameOver = false;  // Флаг окончания игры

    srand(static_cast<unsigned>(time(0)));

    Cell cells[CELLSIZE_M][CELLSIZE_N];
    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            cells[x][y].isHidden = true;
            cells[x][y].isFood = rand() % 100 < CHANCE_FOOD;

            int enemyChance = rand() % 100;
            if (enemyChance < 5) {  // 5% шанс на первый тип врага
                cells[x][y].cellType = Type_Enemy1;
            }
            else if (enemyChance < 10) {  // 5% шанс на второй тип врага
                cells[x][y].cellType = Type_Enemy2;
            }
            else {
                cells[x][y].cellType = static_cast<CellType>(rand() % (CellType::Type_End - 1));
            }
        }
    }

    sf::RenderWindow window(
        sf::VideoMode(static_cast<unsigned int>(CELLSIZE_SCREEN * CELLSIZE_M),
            static_cast<unsigned int>(CELLSIZE_SCREEN * CELLSIZE_N)),
        "NOT MINESWEEPER GAME");

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text textHealthPoint;
    sf::Text textHunger;
    sf::Text textCondition;


    textHealthPoint.setFont(font);
    textHealthPoint.setCharacterSize(CELLSIZE_SCREEN / 2);
    textHealthPoint.setFillColor(sf::Color::Red);
    textHealthPoint.setStyle(sf::Text::Bold | sf::Text::Underlined);

    textHunger.setFont(font);
    textHunger.setCharacterSize(CELLSIZE_SCREEN / 2);
    textHunger.setFillColor(sf::Color::Green);
    textHunger.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textHunger.setPosition(10.f, CELLSIZE_SCREEN);  // Сдвигаем текст голода ниже

    textCondition.setFont(font);
    textCondition.setCharacterSize(CELLSIZE_SCREEN);
    textCondition.setFillColor(sf::Color::Red);
    textCondition.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textCondition.setPosition(10.f, CELLSIZE_SCREEN * CELLSIZE_N - 300.f);  // Сдвигаем текст поражения вниз

    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N];
    sf::Texture textures[TextureType::Texture_End];

    textures[TextureType::Texture_Grass].loadFromFile("grass.png");
    textures[TextureType::Texture_Hill].loadFromFile("hill.png");
    textures[TextureType::Texture_Forest].loadFromFile("forest.png");
    textures[TextureType::Texture_Stone].loadFromFile("stone.png");
    textures[TextureType::Texture_Sand].loadFromFile("sand.png");
    textures[TextureType::Texture_Snow].loadFromFile("snow.png");
    textures[TextureType::Texture_Water].loadFromFile("water.png");
    textures[TextureType::Texture_Hide].loadFromFile("hide.png");
    textures[TextureType::Texture_Soup].loadFromFile("soup.png");
    textures[TextureType::Texture_Enemy1].loadFromFile("enemy1.png");  // Текстура для первого врага
    textures[TextureType::Texture_Enemy2].loadFromFile("enemy2.png");  // Текстура для второго врага

    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            shapes[x][y].setTexture(&textures[TextureType::Texture_Hide]);
            shapes[x][y].setPosition(sf::Vector2f(x * CELLSIZE_SCREEN, y * CELLSIZE_SCREEN));
            shapes[x][y].setSize({ CELLSIZE_SCREEN, CELLSIZE_SCREEN });
        }
    }

    bool mousepressed = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

            if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                mousepressed = false;
            }

            if (!mousepressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                mousepressed = true;
                sf::Vector2i mouseCoord = sf::Mouse::getPosition(window);
                clickTile(healthPoint, hunger, mouseCoord, cells, shapes, textures);
                textHealthPoint.setString("HP: " + std::to_string(healthPoint));
                textHunger.setString("Hunger: " + std::to_string(hunger));

                if (isWinOfGame(cells) && !gameOver) {
                    textCondition.setString("WINNER!!!");
                    gameOver = true;
                }
                else if (isLoseOfGame(healthPoint) && !gameOver) {
                    textCondition.setString("LOSER!!!");
                    gameOver = true;
                }
                else if (isLoseOfHunger(hunger) && !gameOver) {
                    textCondition.setString("STARVED!!!");
                    gameOver = true;
                }
            }
        }

        window.clear();
        for (int x = 0; x < CELLSIZE_M; x++) {
            for (int y = 0; y < CELLSIZE_N; y++) {
                window.draw(shapes[x][y]);
            }
        }
        window.draw(textHealthPoint);
        window.draw(textHunger);
        window.draw(textCondition);
        window.display();
    }

    return 0;
}
