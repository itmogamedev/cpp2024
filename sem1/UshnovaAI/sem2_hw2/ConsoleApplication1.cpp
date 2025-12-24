#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ctime>
#include <vector>

#define CELLSIZE_M 10
#define CELLSIZE_N 10
#define CHANCE_FOOD 10
#define CHANCE_MONSTER 15  // Шанс появления монстра (15%)

#define ENERGY_MAX 100
#define HP_MAX 100

#define CELLSIZE_SCREEN 100.f

enum CellType {
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
    Texture_Grass,
    Texture_Hill,
    Texture_Forest,
    Texture_Stone,
    Texture_Sand,
    Texture_Snow,
    Texture_Water,
    Texture_Hide,
    Texture_Soup,
    Texture_Monster,  // Новый тип текстуры для монстра
    Texture_End
};

struct Cell {
    bool isHidden;
    bool isFood;
    bool hasMonster;  // Есть ли монстр на клетке
    CellType cellType;
};

bool isWinOfGame(const Cell cells[CELLSIZE_M][CELLSIZE_N]) {
    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            if (cells[x][y].isHidden && !cells[x][y].hasMonster) {  // Не считаем клетки с монстрами
                return false;
            }
        }
    }
    return true;
}

bool isLoseOfGame(const int& energy, const int& hp) {
    return energy <= 0 || hp <= 0;
}

void clickTile(int& energy, int& hp,
    const sf::Vector2i& mouseCoord,
    Cell cells[CELLSIZE_M][CELLSIZE_N],
    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N],
    sf::Texture textures[TextureType::Texture_End]) {

    const int x = mouseCoord.x / CELLSIZE_SCREEN;
    const int y = mouseCoord.y / CELLSIZE_SCREEN;

    if (x < 0 || x >= CELLSIZE_M || y < 0 || y >= CELLSIZE_N) return;

    cells[x][y].isHidden = false;

    if (cells[x][y].isFood) {
        shapes[x][y].setTexture(&textures[TextureType::Texture_Soup]);
        energy = std::min(energy + 30, ENERGY_MAX);  // Восстановление энергии
    }
    else if (cells[x][y].hasMonster) {
        shapes[x][y].setTexture(&textures[TextureType::Texture_Monster]);
        hp -= 25;  // Монстр отнимает HP
    }
    else {
        shapes[x][y].setTexture(&textures[cells[x][y].cellType]);
    }
    energy--;  // Тратим энергию на ход
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
            cells[x][y].hasMonster = rand() % 100 < CHANCE_MONSTER;  // Генерация монстров
            cells[x][y].cellType = static_cast<CellType>(rand() % (CellType::Type_End - 1));
        }
    }

    sf::RenderWindow window(
        sf::VideoMode({ static_cast<unsigned int>(CELLSIZE_SCREEN * CELLSIZE_M),
                       static_cast<unsigned int>(CELLSIZE_SCREEN * CELLSIZE_N) }),
        "NOT MINESWEEPER GAME", sf::Style::Close);
    sf::Vector2i mouseCoord;

    sf::Font font("arial.ttf");
  
    // Текст для энергии (зеленый)
    sf::Text textEnergy(font);
    textEnergy.setCharacterSize(24);
    textEnergy.setFillColor(sf::Color::Green);
    textEnergy.setPosition(sf::Vector2f (10.f, 10.f));

    // Текст для HP (красный)
    sf::Text textHP(font);
    textHP.setCharacterSize(24);
    textHP.setFillColor(sf::Color::Red);
    textHP.setPosition(sf::Vector2f(10.f, 40.f));

    // Текст статуса игры
    sf::Text textCondition(font);
    textCondition.setFont(font);
    textCondition.setCharacterSize(50);
    textCondition.setFillColor(sf::Color::Yellow);
    textCondition.setStyle(sf::Text::Bold);
    textCondition.setPosition(sf::Vector2f(CELLSIZE_SCREEN * CELLSIZE_M / 4, CELLSIZE_SCREEN * CELLSIZE_N / 2));

    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N];
    sf::Texture textures[TextureType::Texture_End];

    // Загрузка текстур (добавляем monster.png)
    textures[Texture_Grass].loadFromFile("grass.png");
    textures[Texture_Hill].loadFromFile("hill.png");
    textures[Texture_Forest].loadFromFile("forest.png");
    textures[Texture_Stone].loadFromFile("stone.png");
    textures[Texture_Sand].loadFromFile("sand.png");
    textures[Texture_Snow].loadFromFile("snow.png");
    textures[Texture_Water].loadFromFile("water.png");
    textures[Texture_Hide].loadFromFile("hide.png");
    textures[Texture_Soup].loadFromFile("soup.png");
    textures[Texture_Monster].loadFromFile("monster.png");  // Текстура монстра

    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            shapes[x][y].setSize({ CELLSIZE_SCREEN, CELLSIZE_SCREEN });
            shapes[x][y].setPosition(sf::Vector2f(x * CELLSIZE_SCREEN, y * CELLSIZE_SCREEN));
            shapes[x][y].setTexture(&textures[cells[x][y].isHidden ? Texture_Hide : cells[x][y].cellType]);
        }
    }

    bool mousePressed = false;
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }

            if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                mousePressed = false;
            }

            if (!mousePressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                mousePressed = true;
                mouseCoord = sf::Mouse::getPosition(window);
                clickTile(energy, hp, mouseCoord, cells, shapes, textures);

                // Обновляем текстовые поля
                textEnergy.setString("Energy: " + std::to_string(energy));
                textHP.setString("HP: " + std::to_string(hp));

                if (isWinOfGame(cells))
                    textCondition.setString("YOU WIN!");
                if (isLoseOfGame(energy, hp))
                    textCondition.setString("GAME OVER");
            }
        }

        window.clear();

        // Рисуем клетки
        for (int x = 0; x < CELLSIZE_M; x++) {
            for (int y = 0; y < CELLSIZE_N; y++) {
                window.draw(shapes[x][y]);
            }
        }

        // Рисуем UI
        window.draw(textEnergy);
        window.draw(textHP);

        // Показываем статус игры, если игра окончена
        if (isWinOfGame(cells) || isLoseOfGame(energy, hp))
            window.draw(textCondition);

        window.display();
    }
    return 0;
}