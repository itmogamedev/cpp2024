#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ctime>
#include <vector>
#include <iostream>
#include <string>

#define CELLSIZE_M 10
#define CELLSIZE_N 10
#define CHANCE_FOOD 10    
#define CHANCE_MONSTER 10 
#define ENERGY_MAX 25
#define HP_MAX 100
#define CELLSIZE_SCREEN 100.f

enum CellType {
    Type_Grass, Type_Hill, Type_Forest,
    Type_Stone, Type_Sand, Type_Snow,
    Type_Water, Type_End
};

enum TextureType {
    Texture_Grass, Texture_Hill, Texture_Forest,
    Texture_Stone, Texture_Sand, Texture_Snow,
    Texture_Water, Texture_Hide, Texture_Soup,
    Texture_Monster, Texture_End
};

struct Cell {
    bool isHidden = true;
    bool isFood = false;
    bool hasMonster = false;
    CellType cellType = Type_Grass;
};

bool isWinOfGame(const Cell cells[CELLSIZE_M][CELLSIZE_N]) {
    for (int x = 0; x < CELLSIZE_M; ++x)
        for (int y = 0; y < CELLSIZE_N; ++y)
            if (cells[x][y].isHidden) return false;
    return true;
}

bool isLoseOfGame(int energy, int hp) {
    return energy <= 0 || hp <= 0;
}

void clickTile(int& energy, int& hp, const sf::Vector2i& mousePos,
    Cell cells[CELLSIZE_M][CELLSIZE_N],
    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N],
    const sf::Texture textures[], bool& gameOver) {

    if (gameOver) return;

    int x = mousePos.x / CELLSIZE_SCREEN;
    int y = mousePos.y / CELLSIZE_SCREEN;

    if (x < 0 || x >= CELLSIZE_M || y < 0 || y >= CELLSIZE_N) return;
    if (!cells[x][y].isHidden) return;

    cells[x][y].isHidden = false;
    energy--;

    if (cells[x][y].hasMonster) {
        hp -= 10;
        shapes[x][y].setTexture(&textures[Texture_Monster]);
    }
    else if (cells[x][y].isFood) {
        energy = std::min(energy + 5, ENERGY_MAX);
        hp = std::min(hp + 5, HP_MAX);
        shapes[x][y].setTexture(&textures[Texture_Soup]);
    }
    else {
        shapes[x][y].setTexture(&textures[cells[x][y].cellType]);
    }
}

int main() {

    sf::RenderWindow window(
        sf::VideoMode(CELLSIZE_SCREEN * CELLSIZE_M, CELLSIZE_SCREEN * CELLSIZE_N),
        "Monster Hunter Game"
    );

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font!\n";
        return 1;
    }

    sf::Text energyText("Energy: " + std::to_string(ENERGY_MAX), font, 30);
    energyText.setFillColor(sf::Color::Blue);
    energyText.setPosition(10, 10);

    sf::Text hpText("HP: " + std::to_string(HP_MAX), font, 30);
    hpText.setFillColor(sf::Color::Red);
    hpText.setPosition(10, 50);

    sf::Text statusText("", font, 40);
    statusText.setFillColor(sf::Color::Green);
    statusText.setPosition(window.getSize().x / 2 - 100, 10);
    statusText.setStyle(sf::Text::Bold);

    sf::Texture textures[Texture_End];
    std::string textureFiles[] = {
        "grass.png", "hill.png", "forest.png",
        "stone.png", "sand.png", "snow.png",
        "water.png", "hide.png", "soup.png",
        "monster.png"
    };

    for (int i = 0; i < Texture_End; ++i) {
        if (!textures[i].loadFromFile(textureFiles[i])) {
            std::cerr << "Error loading texture: " << textureFiles[i] << "\n";
            textures[i].create(100, 100); 
        }
    }

    int energy = ENERGY_MAX;
    int hp = HP_MAX;
    bool gameOver = false;
    bool gameWon = false;
    Cell cells[CELLSIZE_M][CELLSIZE_N];
    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N];

    srand(time(nullptr));
    for (int x = 0; x < CELLSIZE_M; ++x) {
        for (int y = 0; y < CELLSIZE_N; ++y) {
            cells[x][y] = {
                true,
                (rand() % 100) < CHANCE_FOOD,
                (rand() % 100) < CHANCE_MONSTER,
                static_cast<CellType>(rand() % (Type_End - 1))
            };

            shapes[x][y].setSize({ CELLSIZE_SCREEN, CELLSIZE_SCREEN });
            shapes[x][y].setPosition(x * CELLSIZE_SCREEN, y * CELLSIZE_SCREEN);
            shapes[x][y].setTexture(&textures[Texture_Hide]);
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {
                clickTile(energy, hp, sf::Mouse::getPosition(window), cells, shapes, textures, gameOver);
                energyText.setString("Energy: " + std::to_string(energy));
                hpText.setString("HP: " + std::to_string(hp));
            }
        }

        if (!gameOver && !gameWon) {
            if (isLoseOfGame(energy, hp)) {
                gameOver = true;
                statusText.setString("GAME OVER");
                statusText.setFillColor(sf::Color::Red);
            }
            else if (isWinOfGame(cells)) {
                gameWon = true;
                statusText.setString("YOU WIN!");
                statusText.setFillColor(sf::Color::Yellow);
            }
        }

        window.clear(sf::Color(50, 50, 50));

        for (int x = 0; x < CELLSIZE_M; ++x) {
            for (int y = 0; y < CELLSIZE_N; ++y) {
                window.draw(shapes[x][y]);
            }
        }

        window.draw(energyText);
        window.draw(hpText);
        window.draw(statusText);

        window.display();
    }

    return 0;
}
