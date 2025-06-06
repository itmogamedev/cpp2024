#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ctime>

#define CELLSIZE_M 10
#define CELLSIZE_N 10
#define CHANCE_FOOD 10
#define CHANCE_ENEMY 5

#define ENERGY_MAX 25
#define HP_MAX 100
#define ENEMY_DAMAGE 13

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
    Texture_Enemy,
    Texture_End
};

struct Cell {
    bool isHidden;
    bool isFood;
    bool isEnemy;
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

bool isLoseOfGame(const int& energy, const int& hp) {
    return energy <= 0 || hp <= 0;
}

void clickTile(
    int& energy,
    int& hp,
    const sf::Vector2i& mouseCoord,
    Cell cells[CELLSIZE_M][CELLSIZE_N],
    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N],
    sf::Texture textures[TextureType::Texture_End]
) {
    int x = mouseCoord.x / CELLSIZE_SCREEN;
    int y = mouseCoord.y / CELLSIZE_SCREEN;

    if (x < 0 || x >= CELLSIZE_M || y < 0 || y >= CELLSIZE_N || !cells[x][y].isHidden)
        return;

    cells[x][y].isHidden = false;

    if (cells[x][y].isEnemy) {
        hp -= ENEMY_DAMAGE;
        shapes[x][y].setTexture(&textures[TextureType::Texture_Enemy]);
    }
    else if (cells[x][y].isFood) {
        energy = ENERGY_MAX;
        shapes[x][y].setTexture(&textures[TextureType::Texture_Soup]);
    }
    else {
        shapes[x][y].setTexture(&textures[cells[x][y].cellType]);
    }
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
            cells[x][y].cellType = static_cast<CellType>(rand() % (CellType::Type_End - 1));
        }
    }

    sf::RenderWindow window(
        sf::VideoMode({ static_cast <unsigned int> (CELLSIZE_SCREEN * CELLSIZE_M),
            static_cast <unsigned int> (CELLSIZE_SCREEN * CELLSIZE_N) }),
        "NOT MINESWEEPER GAME", sf::State::Windowed);
    sf::Vector2i mouseCoord;

    sf::Font font("arial.ttf");

    sf::Text textEnergy(font);
    sf::Text textHP(font);
    sf::Text textCondition(font);

    textEnergy.setCharacterSize(CELLSIZE_SCREEN / 2);
    textEnergy.setFillColor(sf::Color::Red);
    textEnergy.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textHP.setCharacterSize(CELLSIZE_SCREEN / 2);
    textHP.setFillColor(sf::Color::Red);
    textHP.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textEnergy.setPosition(sf::Vector2f(10, 10));
    textHP.setPosition(sf::Vector2f(790, 10));
    textCondition.setFillColor(sf::Color::Red);
    textCondition.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textCondition.setPosition(sf::Vector2f(300, 10));

    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N];
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
    textures[Texture_Enemy].loadFromFile("enemy.png");

    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            shapes[x][y].setSize({ CELLSIZE_SCREEN, CELLSIZE_SCREEN });
            shapes[x][y].setPosition(sf::Vector2f(x * CELLSIZE_SCREEN, y * CELLSIZE_SCREEN));
            shapes[x][y].setTexture(&textures[Texture_Hide]);
        }
    }

    bool mousePressed = false;

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            mousePressed = false;

        if (!mousePressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            mousePressed = true;
            sf::Vector2i mouseCoord = sf::Mouse::getPosition(window);

            clickTile(energy, hp, mouseCoord, cells, shapes, textures);
            energy--;

            if (isWinOfGame(cells)) {
                textCondition.setString("YOU WIN!");
            }
            else if (isLoseOfGame(energy, hp)) {
                textCondition.setString("YOU LOSE!");
            }
        }

        textEnergy.setString("Energy: " + std::to_string(energy));
        textHP.setString("HP: " + std::to_string(hp));

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

    return 0;
}
