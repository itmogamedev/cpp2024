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
#define CELLSIZE_W 10
#define CELLSIZE_H 10
#define CHANCE_FOOD 10
#define CHANCE_MONSTER 5
#define ENERGY_MAX 100
#define HP_MAX 5
#define CELLSIZE_SCREEN 75.f

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
    bool isHidden;
    bool isFood;
    bool isMonster;
    CellType cellType;
};

bool isWinOfGame(const Cell cells[CELLSIZE_W][CELLSIZE_H]) {
    bool winCondition = true;
    for (int x = 0; x < CELLSIZE_W; x++) {
        for (int y = 0; y < CELLSIZE_H; y++) {
            if (cells[x][y].isHidden) {
                winCondition = false;
                break;
            }
        }
    }
    return winCondition;
}

bool isLoseOfGame(const int& energy, int& hp)
{
    return energy == 0 or hp == 0;
}

void clickTile(int& energy, int& hp,
    const sf::Vector2i& mouseCoord,
    Cell cells[CELLSIZE_W][CELLSIZE_H],
    sf::RectangleShape shapes[CELLSIZE_W][CELLSIZE_H],
    sf::Texture textures[TextureType::Texture_End]) {

    const int x = mouseCoord.x < 0 ?
        0 :
        mouseCoord.x > CELLSIZE_SCREEN * CELLSIZE_W ?
        CELLSIZE_W :
        mouseCoord.x / CELLSIZE_SCREEN;

    const int y = mouseCoord.y < 0 ?
        0 :
        mouseCoord.y > CELLSIZE_SCREEN * CELLSIZE_H ?
        CELLSIZE_H :
        mouseCoord.y / CELLSIZE_SCREEN;

    cells[x][y].isHidden = false;

    if (cells[x][y].isFood)
    {
        shapes[x][y].setTexture(&textures[TextureType::Texture_Soup]);
        energy = ENERGY_MAX;
    }
    if (cells[x][y].isMonster)
    {
        shapes[x][y].setTexture(&textures[TextureType::Texture_Monster]);
        hp = hp - 1;
    }
    if (cells[x][y].isFood == false and cells[x][y].isMonster == false)
    {
        shapes[x][y].setTexture(&textures[cells[x][y].cellType]);
    }
}

int main() {
    int energy = ENERGY_MAX;
    int hp = HP_MAX;

    srand(time(0));

    Cell cells[CELLSIZE_W][CELLSIZE_H];
    for (int x = 0; x < CELLSIZE_W; x++) {
        for (int y = 0; y < CELLSIZE_H; y++) {
            cells[x][y].isHidden = true;
            int coin = rand() % 100;
            cells[x][y].isFood = coin < CHANCE_FOOD;
            cells[x][y].isMonster = coin > (100 - CHANCE_MONSTER);
            cells[x][y].cellType = static_cast<CellType>
                (rand() % (CellType::Type_End - 1));
        }
    }

    sf::RenderWindow window(
        sf::VideoMode({ static_cast <unsigned int> (CELLSIZE_SCREEN * CELLSIZE_W),
            static_cast <unsigned int> (CELLSIZE_SCREEN * CELLSIZE_H) }),
        "NOT MINESWEEPER GAME", sf::State::Windowed);
    sf::Vector2i mouseCoord;

    sf::Font font("arial.ttf");
    sf::Text textEnergy(font);
    sf::Text textHp(font);
    sf::Text textCondition(font);
    textEnergy.setCharacterSize(CELLSIZE_SCREEN / 2);
    textEnergy.setFillColor(sf::Color::Yellow);
    textEnergy.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textHp.setCharacterSize(CELLSIZE_SCREEN / 2);
    textHp.setFillColor(sf::Color::Red);
    textHp.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textHp.setPosition(sf::Vector2f(0, CELLSIZE_H * 3));
    textCondition.setCharacterSize(CELLSIZE_SCREEN * 2);
    textCondition.setFillColor(sf::Color::Red);
    textCondition.setStyle(sf::Text::Bold | sf::Text::Underlined);
    sf::RectangleShape shapes[CELLSIZE_W][CELLSIZE_H];
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


    for (int x = 0; x < CELLSIZE_W; x++) {
        for (int y = 0; y < CELLSIZE_H; y++) {

            //TODO функцию а не напрямую
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
                textHp.setString(std::to_wstring(hp));

                if (isWinOfGame(cells))
                    textCondition.setString("WINNER!!!");
                if (isLoseOfGame(energy, hp))
                    textCondition.setString("LOSER!!!");
            }
        }

        window.clear();
        for (int x = 0; x < CELLSIZE_W; x++) {
            for (int y = 0; y < CELLSIZE_H; y++) {
                window.draw(shapes[x][y]);
            }
        }
        window.draw(textEnergy);
        window.draw(textHp);
        window.draw(textCondition);
        window.display();
    }
}