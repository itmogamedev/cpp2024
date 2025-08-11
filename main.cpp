#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ctime>
#include <string>
#include <algorithm>

#define CELLSIZE_M 10
#define CELLSIZE_N 10
#define CHANCE_FOOD 10
#define CHANCE_MONSTER 20  
#define ENERGY_MAX 100
#define HP_MAX 100        // Добавлена недостающая константа
#define CELLSIZE_SCREEN 100.f
#define MONSTER_DAMAGE 25
#define MIN_MONSTER_DAMAGE 5
#define MAX_MONSTER_DAMAGE 15
#define FOOD_ENERGY 30

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
    Texture_Monster,
    Texture_End

};

struct Cell {
    bool isHidden = true;
    bool isFood = false;
    bool hasMonster = false;
    bool wasRevealed = false; // Добавлено для отслеживания открытых клеток
    int monsterDamage = 0;    // Хранение урона от монстра
    CellType cellType;
};

struct Player {
    int energy = ENERGY_MAX;
    int hp = HP_MAX;
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



bool isLoseOfGame(const Player& player) {
    return player.energy <= 0 || player.hp <= 0;
}

void clickTile(Player& player,
    const sf::Vector2i& mouseCoord,
    Cell cells[CELLSIZE_M][CELLSIZE_N],
    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N],
    sf::Texture textures[],
    sf::Text& damageText) {

    int x = std::clamp(mouseCoord.x / static_cast<int>(CELLSIZE_SCREEN), 0, CELLSIZE_M - 1);
    int y = std::clamp(mouseCoord.y / static_cast<int>(CELLSIZE_SCREEN), 0, CELLSIZE_N - 1);

    if (cells[x][y].isHidden) {
        cells[x][y].isHidden = false;

        if (cells[x][y].isFood) {
            shapes[x][y].setTexture(&textures[Texture_Soup]);
            player.energy = std::min(player.energy + FOOD_ENERGY, ENERGY_MAX);
            player.hp = std::min(player.hp + FOOD_ENERGY, HP_MAX);  // Восстанавливаем HP
        }
        else if (cells[x][y].hasMonster) {
            shapes[x][y].setTexture(&textures[Texture_Monster]);
            cells[x][y].monsterDamage = MIN_MONSTER_DAMAGE + rand() % (MAX_MONSTER_DAMAGE - MIN_MONSTER_DAMAGE + 1);
            player.hp = std::max(player.hp - cells[x][y].monsterDamage, 0);

            damageText.setString("-" + std::to_string(cells[x][y].monsterDamage));
            damageText.setPosition(sf::Vector2f(
                x * CELLSIZE_SCREEN + 20.f,
                y * CELLSIZE_SCREEN + 20.f
            ));
        }
        else {
            shapes[x][y].setTexture(&textures[cells[x][y].cellType]);
        }

        player.energy--;
    }
}

int main() {
    Player player;

    srand(time(0));

    Cell cells[CELLSIZE_M][CELLSIZE_N];
    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            cells[x][y].isHidden = true;
            cells[x][y].isFood = rand() % 100 < CHANCE_FOOD;
            cells[x][y].hasMonster = rand() % 100 < CHANCE_MONSTER;
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
    sf::Text statsText(font);
    sf::Text gameResultText(font);
    sf::Text damageText(font);

    textEnergy.setCharacterSize(CELLSIZE_SCREEN / 2);
    textEnergy.setFillColor(sf::Color::Red);
    textEnergy.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textCondition.setCharacterSize(CELLSIZE_SCREEN);
    textCondition.setFillColor(sf::Color::Red);
    textCondition.setStyle(sf::Text::Bold | sf::Text::Underlined);
    statsText.setCharacterSize(CELLSIZE_SCREEN / 2);
    statsText.setFillColor(sf::Color::Red);
    statsText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    gameResultText.setCharacterSize(CELLSIZE_SCREEN / 2);
    gameResultText.setFillColor(sf::Color::Green);
    gameResultText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    damageText.setCharacterSize(CELLSIZE_SCREEN / 2);
    damageText.setFillColor(sf::Color::Green);
    damageText.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N];
    sf::Texture textures[TextureType::Texture_End];
    textures[TextureType::Texture_Grass] = sf::Texture("grass.png");
    textures[TextureType::Texture_Hill] = sf::Texture("hill.png");
    textures[TextureType::Texture_Forest] = sf::Texture("forest.png");
    textures[TextureType::Texture_Stone] = sf::Texture("stone.png");
    textures[TextureType::Texture_Sand] = sf::Texture("sand.png");
    textures[TextureType::Texture_Snow] = sf::Texture("snow.png");
    textures[TextureType::Texture_Water] = sf::Texture("water.png");
    textures[TextureType::Texture_Hide] = sf::Texture("hide.png");
    textures[TextureType::Texture_Soup] = sf::Texture("soup.png");
    textures[TextureType::Texture_Monster] = sf::Texture("monster.png");

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
    bool showDamage = false;
    sf::Clock damageClock;
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
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                clickTile(player, mousePos, cells, shapes, textures, damageText);
                showDamage = true;
                damageClock.restart();
            }
              
         textEnergy.setString(std::to_wstring(player.energy));

                if (isWinOfGame(cells))
                    textCondition.setString("WINNER!!!");
                if (isLoseOfGame(player))
                    textCondition.setString("LOSER!!!");
            
        }
        if (showDamage && damageClock.getElapsedTime().asSeconds() > 1.0f) {
            showDamage = false;
        }
        statsText.setString("Energy: " + std::to_string(player.energy) +
            "\nHP: " + std::to_string(player.hp));
        if (isWinOfGame(cells)) {
            gameResultText.setString("YOU WIN!");
        }
        else if (isLoseOfGame(player)) {
            gameResultText.setString("GAME OVER");
        }

        window.clear();
        for (int x = 0; x < CELLSIZE_M; x++) {
            for (int y = 0; y < CELLSIZE_N; y++) {
                window.draw(shapes[x][y]);
            }
        }

        if (showDamage) {
            window.draw(damageText);
        }

        // Отрисовка UI
        window.draw(statsText);
        if (isWinOfGame(cells) || isLoseOfGame(player)) {
            window.draw(gameResultText);
        }

        window.draw(textEnergy);
        window.draw(textCondition);
        window.display();


    }
    return 0;
}