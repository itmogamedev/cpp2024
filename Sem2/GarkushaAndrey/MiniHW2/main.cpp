#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ctime>
#include <iostream>

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
#define CHANCE_MONSTER 5
#define ENERGY_MAX 100
#define HP_MAX 3
#define CELLSIZE_SCREEN 100.f

enum CellType {
    Type_Grass,
    Type_Hill,
    Type_Forest,
    Type_Stone,
    Type_Sand,
    Type_Snow,
    Type_Water,
    Type_End,
    Type_Monster
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
    Texture_HP,
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
            if (cells[x][y].isHidden) {
                return false;
            }
        }
    }
    return true;
}

bool isLoseOfGame(const int& energy, const int& hp_counts) {
    return energy <= 0 || hp_counts <= 0;
}

void clickTile(int& energy,
    const sf::Vector2i& mouseCoord,
    Cell cells[CELLSIZE_M][CELLSIZE_N],
    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N],
    sf::Texture textures[TextureType::Texture_End],
    int& hp_counts) {

    const int x = mouseCoord.x < 0 ?
        0 :
        mouseCoord.x >= static_cast<int>(CELLSIZE_SCREEN * CELLSIZE_M) ?
        CELLSIZE_M - 1 :
        mouseCoord.x / static_cast<int>(CELLSIZE_SCREEN);

    const int y = mouseCoord.y < 0 ?
        0 :
        mouseCoord.y >= static_cast<int>(CELLSIZE_SCREEN * CELLSIZE_N) ?
        CELLSIZE_N - 1 :
        mouseCoord.y / static_cast<int>(CELLSIZE_SCREEN);

    if (x >= CELLSIZE_M || y >= CELLSIZE_N) return;

    if (cells[x][y].isHidden) {
        cells[x][y].isHidden = false;

        if (cells[x][y].isFood) {
            shapes[x][y].setTexture(&textures[TextureType::Texture_Soup]);
            energy = ENERGY_MAX;
        }
        else if (cells[x][y].isMonster) {
            shapes[x][y].setTexture(&textures[TextureType::Texture_Monster]);
            --hp_counts;
        }
        else {
            shapes[x][y].setTexture(&textures[cells[x][y].cellType]);
        }
    }
}

int main() {
    int energy = ENERGY_MAX;
    int hp_counts = HP_MAX;

    srand(static_cast<unsigned int>(time(0)));

    Cell cells[CELLSIZE_M][CELLSIZE_N];
    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            cells[x][y].isHidden = true;
            cells[x][y].isFood = rand() % 100 < CHANCE_FOOD;
            cells[x][y].isMonster = rand() % 100 < CHANCE_MONSTER;
            cells[x][y].cellType = static_cast<CellType>(rand() % (CellType::Type_End - 1));
        }
    }

    sf::RenderWindow window(
        sf::VideoMode(
            static_cast<unsigned int>(CELLSIZE_SCREEN * CELLSIZE_M),
            static_cast<unsigned int>(CELLSIZE_SCREEN * CELLSIZE_N)
        ),
        "NOT MINESWEEPER GAME"
    );

    sf::Vector2i mouseCoord;

    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Error: Could not load font 'Arial.ttf'" << std::endl;
        return -1;
    }

    sf::Text textEnergy;
    sf::Text textCondition;
    textEnergy.setFont(font);
    textCondition.setFont(font);

    textEnergy.setCharacterSize(static_cast<unsigned int>(CELLSIZE_SCREEN / 2));
    textEnergy.setFillColor(sf::Color::Red);
    textEnergy.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textEnergy.setPosition(10.f, 10.f);

    textCondition.setCharacterSize(static_cast<unsigned int>(CELLSIZE_SCREEN));
    textCondition.setFillColor(sf::Color::Red);
    textCondition.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textCondition.setPosition(
        (CELLSIZE_M * CELLSIZE_SCREEN - textCondition.getGlobalBounds().width) / 2.f,
        (CELLSIZE_N * CELLSIZE_SCREEN - textCondition.getGlobalBounds().height) / 2.f
    );

    sf::Text textHP;
    textHP.setFont(font);
    textHP.setCharacterSize(static_cast<unsigned int>(CELLSIZE_SCREEN / 2));
    textHP.setFillColor(sf::Color::Red);
    textHP.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textHP.setPosition(140.f, 10.f);

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
    textures[TextureType::Texture_Monster].loadFromFile("monster.png");
    textures[TextureType::Texture_HP].loadFromFile("heart.png");

    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            if (cells[x][y].isHidden)
                shapes[x][y].setTexture(&textures[TextureType::Texture_Hide]);
            else
                shapes[x][y].setTexture(&textures[cells[x][y].cellType]);

            shapes[x][y].setPosition(sf::Vector2f(x * CELLSIZE_SCREEN, y * CELLSIZE_SCREEN));
            shapes[x][y].setSize(sf::Vector2f(CELLSIZE_SCREEN, CELLSIZE_SCREEN));
        }
    }

    sf::RectangleShape hpShape;
    hpShape.setTexture(&textures[TextureType::Texture_HP]);
    hpShape.setPosition(175.f, 27.f);
    hpShape.setSize(sf::Vector2f(30.f, 30.f));

    textEnergy.setString(std::to_string(energy));
    textHP.setString(std::to_string(hp_counts));

    bool mousepressed = false;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.scancode == sf::Keyboard::Scan::Escape)
                    window.close();
            }
        }

        if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            mousepressed = false;
        }

        if (!mousepressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            mousepressed = true;
            mouseCoord = sf::Mouse::getPosition(window);

            clickTile(energy, mouseCoord, cells, shapes, textures, hp_counts);
            energy--;

            textEnergy.setString(std::to_string(energy));
            textHP.setString(std::to_string(hp_counts));

            if (isWinOfGame(cells)) {
                textCondition.setString("WINNER!!!");
                textCondition.setPosition(
                    (CELLSIZE_M * CELLSIZE_SCREEN - textCondition.getGlobalBounds().width) / 2.f,
                    (CELLSIZE_N * CELLSIZE_SCREEN - textCondition.getGlobalBounds().height) / 2.f
                );
            }
            if (isLoseOfGame(energy, hp_counts)) {
                textCondition.setString("LOSER!!!");
                textCondition.setPosition(
                    (CELLSIZE_M * CELLSIZE_SCREEN - textCondition.getGlobalBounds().width) / 2.f,
                    (CELLSIZE_N * CELLSIZE_SCREEN - textCondition.getGlobalBounds().height) / 2.f
                );
            }
        }

        window.clear();

        for (int x = 0; x < CELLSIZE_M; x++) {
            for (int y = 0; y < CELLSIZE_N; y++) {
                window.draw(shapes[x][y]);
            }
        }

        window.draw(textHP);
        window.draw(hpShape);
        window.draw(textEnergy);
        if (isWinOfGame(cells) || isLoseOfGame(energy, hp_counts)) {
            window.draw(textCondition);
        }

        window.display();
    }

    return 0;
}