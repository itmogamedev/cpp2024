#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <ctime>

#define CELLSIZE_M 10
#define CELLSIZE_N 10
#define CHANCE_FOOD 10
#define CHANCE_MONSTER 15
#define ENERGY_MAX 100
#define HP_MAX 25
#define CELLSIZE_SCREEN 100.f
#define MONSTER_DAMAGE 5

enum CellType {
    Type_Grass,
    Type_Hill,
    Type_Forest,
    Type_Stone,
    Type_Sand,
    Type_Snow,
    Type_Water,
    Type_End,
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
    Texture_Monster,
    Texture_End,
};

struct Cell {
    bool isHidden;
    bool isFood;
    bool isMonster;
    CellType cellType;
};

bool isWinOfGame(const Cell cells[CELLSIZE_M][CELLSIZE_N]) {
    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            if (cells[x][y].isHidden)
                return false;
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

    int x = mouseCoord.x / static_cast<int>(CELLSIZE_SCREEN);
    int y = mouseCoord.y / static_cast<int>(CELLSIZE_SCREEN);

    if (x < 0 || x >= CELLSIZE_M || y < 0 || y >= CELLSIZE_N)
        return;

    if (!cells[x][y].isHidden)
        return;

    cells[x][y].isHidden = false;
    energy--;

    if (cells[x][y].isMonster) {
        shapes[x][y].setTexture(&textures[TextureType::Texture_Monster]);
        hp -= MONSTER_DAMAGE;
    }
    else if (cells[x][y].isFood) {
        shapes[x][y].setTexture(&textures[TextureType::Texture_Soup]);
        energy = ENERGY_MAX;
    }
    else {
        shapes[x][y].setTexture(&textures[cells[x][y].cellType]);
    }
}

int main() {
    int energy = ENERGY_MAX;
    int hp = HP_MAX;

    srand(static_cast<unsigned>(time(0)));

    Cell cells[CELLSIZE_M][CELLSIZE_N];
    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N];

    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            cells[x][y].isHidden = true;
            cells[x][y].isFood = rand() % 100 < CHANCE_FOOD;
            cells[x][y].isMonster = rand() % 100 < CHANCE_MONSTER;
            cells[x][y].cellType = static_cast<CellType>(rand() % (Type_End - 1));

            shapes[x][y].setPosition(sf::Vector2f(x * CELLSIZE_SCREEN, y * CELLSIZE_SCREEN));
            shapes[x][y].setSize({ CELLSIZE_SCREEN, CELLSIZE_SCREEN });
        }
    }

    sf::RenderWindow window(
        sf::VideoMode(static_cast<unsigned int>(CELLSIZE_SCREEN * CELLSIZE_M),
            static_cast<unsigned int>(CELLSIZE_SCREEN * CELLSIZE_N)),
        "NOT MINESWEEPER GAME",
        sf::Style::Default);

    sf::Font font;
    font.loadFromFile("chilispepper.ttf");

    sf::Text textEnergy;
    textEnergy.setFont(font);
    textEnergy.setCharacterSize(CELLSIZE_SCREEN / 2);
    textEnergy.setFillColor(sf::Color::Red);
    textEnergy.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::Text textHP;
    textHP.setFont(font);
    textHP.setCharacterSize(CELLSIZE_SCREEN / 2);
    textHP.setFillColor(sf::Color::Green);
    textHP.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textHP.setPosition(0, CELLSIZE_SCREEN / 2);

    sf::Text textCondition;
    textCondition.setFont(font);
    textCondition.setCharacterSize(CELLSIZE_SCREEN);
    textCondition.setFillColor(sf::Color::Red);
    textCondition.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::Texture textures[TextureType::Texture_End];
    textures[Texture_Grass].loadFromFile("grass.png");
    textures[Texture_Hill].loadFromFile("hill.png");
    textures[Texture_Forest].loadFromFile("forest.png");
    textures[Texture_Stone].loadFromFile("stone.png");
    textures[Texture_Sand].loadFromFile("sand.png");
    textures[Texture_Snow].loadFromFile("snow.png");
    textures[Texture_Water].loadFromFile("water.png");
    textures[Texture_Hide].loadFromFile("hide.png");
    textures[Texture_Soup].loadFromFile("soup.png");
    textures[Texture_Monster].loadFromFile("monster.png");

    // Устанавливаем изначально скрытые текстуры
    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            shapes[x][y].setTexture(&textures[Texture_Hide]);
        }
    }

    bool mousepressed = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            mousepressed = false;
        }

        if (!mousepressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            mousepressed = true;
            sf::Vector2i mouseCoord = sf::Mouse::getPosition(window);

            clickTile(energy, hp, mouseCoord, cells, shapes, textures);
            textEnergy.setString(std::to_wstring(energy));
            textHP.setString(std::to_wstring(hp));

            if (isWinOfGame(cells))
                textCondition.setString("WINNER!!!");
            if (isLoseOfGame(energy, hp))
                textCondition.setString("LOSER!!!");
        }

        window.clear();
        for (int x = 0; x < CELLSIZE_M; x++) {
            for (int y = 0; y < CELLSIZE_N; y++) {
                window.draw(shapes[x][y]);
            }
        }
        window.draw(textEnergy);
        window.draw(textHP);
        window.draw(textCondition);
        window.display();
    }
}
