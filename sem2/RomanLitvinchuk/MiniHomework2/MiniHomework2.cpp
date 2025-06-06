#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <optional>
#include <ctime>


#define CELLSIZE_M 10
#define CELLSIZE_N 10
#define CHANCE_FOOD 10
#define CHANCE_MONSTER 10

#define ENERGY_MAX 100
#define HEALTH_MAX 100

#define CELLSIZE_SCREEN 100.f

enum CellType {
    Type_Grass,
    Type_Hill,
    Type_Forest,
    Type_Stone,
    Type_Sand,
    Type_Snow,
    Type_Water,
    Type_Monster,
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

bool isLoseOfGame(const int& energy, const int& health) {
    return ( (energy <= 0) or (health <= 0) );
}

void clickTile(int& energy, int& health,
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
        health += 20;
    }
    else
    {
        if (cells[x][y].isMonster)
        {
            shapes[x][y].setTexture(&textures[TextureType::Texture_Monster]);
            health -= 20;
        }
        else {
            shapes[x][y].setTexture(&textures[cells[x][y].cellType]);
        }
    }
}

int main() {
    int energy = ENERGY_MAX;
    int health = HEALTH_MAX;

    srand(time(0));

    Cell cells[CELLSIZE_M][CELLSIZE_N];
    for (int x = 0; x < CELLSIZE_M; x++) {
        for (int y = 0; y < CELLSIZE_N; y++) {
            cells[x][y].isHidden = true;
            cells[x][y].isFood = rand() % 100 < CHANCE_FOOD;
            if (cells[x][y].isFood == false) 
            {
                cells[x][y].isMonster = rand() % 100 < CHANCE_MONSTER;
            }
            cells[x][y].cellType = static_cast<CellType>
                (rand() % (CellType::Type_End - 1));
        }
    }

    sf::RenderWindow window(
        sf::VideoMode({ static_cast <unsigned int> (CELLSIZE_SCREEN * CELLSIZE_M),
            static_cast <unsigned int> (CELLSIZE_SCREEN * CELLSIZE_N) }),
        "NOT MINESWEEPER GAME", sf::Style::Default);
    sf::Vector2i mouseCoord;

    sf::Font font;
    font.loadFromFile("Arial.txt");
    sf::Text textEnergy;
    textEnergy.setFont(font);
    sf::Text textCondition;
    textCondition.setFont(font);
    textEnergy.setCharacterSize(CELLSIZE_SCREEN / 2);
    textEnergy.setFillColor(sf::Color::Red);
    textEnergy.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textCondition.setCharacterSize(CELLSIZE_SCREEN);
    textCondition.setFillColor(sf::Color::Red);
    textCondition.setStyle(sf::Text::Bold | sf::Text::Underlined);
    sf::RectangleShape shapes[CELLSIZE_M][CELLSIZE_N];

    sf::Texture textures[TextureType::Texture_End];
    sf::Texture grass;
    grass.loadFromFile("grass.png");
    textures[TextureType::Texture_Grass] = grass;
    sf::Texture hill;
    hill.loadFromFile("hill.png");
    textures[TextureType::Texture_Hill] = hill;
    sf::Texture forest;
    forest.loadFromFile("forest.png");
    textures[TextureType::Texture_Forest] = forest;
    sf::Texture stone;
    stone.loadFromFile("stone.png");
    textures[TextureType::Texture_Stone] = stone;
    sf::Texture sand;
    sand.loadFromFile("sand.png");
    textures[TextureType::Texture_Sand] = sand;
    sf::Texture snow;
    snow.loadFromFile("snow.png");
    textures[TextureType::Texture_Snow] = snow;
    sf::Texture water;
    water.loadFromFile("water.png");
    textures[TextureType::Texture_Water] = water;
    sf::Texture hide;
    hide.loadFromFile("hide.png");
    textures[TextureType::Texture_Hide] = hide;
    sf::Texture soup;
    soup.loadFromFile("soup.png");
    textures[TextureType::Texture_Soup] = soup;
    sf::Texture monster;
    monster.loadFromFile("monster.png");
    textures[TextureType::Texture_Monster] = monster;


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

        //while (const std::optional event = window.pollEvent()) {
        //    if (event->is<sf::Event::Closed>())
        //        window.close();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            //if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            //    if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
            //        window.close();
            //}

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }

            if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                mousepressed = false;
            }

            if (!mousepressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                mousepressed = true;
                mouseCoord = sf::Mouse::getPosition(window);

                clickTile(energy, health, mouseCoord, cells, shapes, textures);
                energy--;
                textEnergy.setString(std::to_wstring(energy));

                if (isWinOfGame(cells))
                    textCondition.setString("WINNER!!!");
                if (isLoseOfGame(energy, health))
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