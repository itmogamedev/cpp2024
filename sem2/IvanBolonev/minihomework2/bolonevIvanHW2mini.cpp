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

#define CHANCE_ENEMY 10

#define ENERGY_MAX 25

#define HP_MAX 10

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
    Texture_Water,
    Texture_Grass,
    Texture_Hill,
    Texture_Forest,
    Texture_Stone,
    Texture_Sand,
    Texture_Snow,
    
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
                return false; // Если есть скрытые клетки, игрок не выиграл
            }
        }
    }
    return true; // Все клетки открыты, игрок выиграл
}
bool isLoseOfGame(const int& energy) {
    return energy <= 0;
}

void clickTile(int& energy,int& HP,
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

    if (cells[x][y].isEnemy) {
        shapes[x][y].setTexture(&textures[TextureType::Texture_Enemy]);
        HP--; // Уменьшаем здоровье при нажатии на противника
    }
    else {
        shapes[x][y].setTexture(&textures[cells[x][y].cellType]);
    }

    if (cells[x][y].isFood) {
        shapes[x][y].setTexture(&textures[TextureType::Texture_Soup]);
        energy = ENERGY_MAX; // Восстанавливаем энергию
        HP = HP_MAX;
    }
}

int main() {
    int energy = ENERGY_MAX;
    int HP = HP_MAX;
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
        "NOT MINESWEEPER GAME", sf::Style ::Default);
    sf::Vector2i mouseCoord;

    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Ошибка: не удалось загрузить шрифт Arial.ttf" << std::endl;
        return -1; // Обработка ошибки
    }
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

    sf::Text textHP; // Текст для отображения здоровья
    textHP.setFont(font);
    textHP.setCharacterSize(CELLSIZE_SCREEN / 2);
    textHP.setFillColor(sf::Color::Red);
    textHP.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textHP.setPosition(window.getSize().x - textHP.getGlobalBounds().width - 200, 10);


    // Загрузка текстур с проверкой на ошибки
    if (!textures[TextureType::Texture_Grass].loadFromFile("grass.png")) {
        std::cerr << "Ошибка: не удалось загрузить текстуру grass.png" << std::endl;
        return -1; // Обработка ошибки
    }
    if (!textures[TextureType::Texture_Hill].loadFromFile("hill.png")) {
        std::cerr << "Ошибка: не удалось загрузить текстуру hill.png" << std::endl;
        return -1; // Обработка ошибки
    }
    if (!textures[TextureType::Texture_Forest].loadFromFile("forest.png")) {
        std::cerr << "Ошибка: не удалось загрузить текстуру forest.png" << std::endl;
        return -1; // Обработка ошибки
    }
    if (!textures[TextureType::Texture_Stone].loadFromFile("stone.png")) {
        std::cerr << "Ошибка: не удалось загрузить текстуру stone.png" << std::endl;
        return -1; // Обработка ошибки
    }
    if (!textures[TextureType::Texture_Sand].loadFromFile("sand.png")) {
        std::cerr << "Ошибка: не удалось загрузить текстуру sand.png" << std::endl;
        return -1; // Обработка ошибки
    }
    if (!textures[TextureType::Texture_Snow].loadFromFile("snow.png")) {
        std::cerr << "Ошибка: не удалось загрузить текстуру snow.png" << std::endl;
        return -1; // Обработка ошибки
    }
    if (!textures[TextureType::Texture_Water].loadFromFile("water.png")) {
        std::cerr << "Ошибка: не удалось загрузить текстуру water.png" << std::endl;
        return -1; // Обработка ошибки
    }
    if (!textures[TextureType::Texture_Hide].loadFromFile("hide.png")) {
        std::cerr << "Ошибка: не удалось загрузить текстуру hide.png" << std::endl;
        return -1; // Обработка ошибки
    }
    if (!textures[TextureType::Texture_Soup].loadFromFile("soup.png")) {
        std::cerr << "Ошибка: не удалось загрузить текстуру soup.png" << std::endl;
        return -1; // Обработка ошибки
    }
    if (!textures[TextureType::Texture_Enemy].loadFromFile("enemy.png")) {
        std::cerr << "Ошибка: не удалось загрузить текстуру enemy.png" << std::endl;
        return -1; // Обработка ошибки
    }


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
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                mousepressed = false;
            }

            if (!mousepressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                mousepressed = true;
                mouseCoord = sf::Mouse::getPosition(window);

                clickTile(energy, HP, mouseCoord, cells, shapes, textures);
                energy--;
                textEnergy.setString(std::to_wstring(energy));
                textHP.setString("HP: " + std::to_string(HP)); // Обновление текста здоровья

                if (isWinOfGame(cells))
                    textCondition.setString("WINNER!!!");
                if (isLoseOfGame(energy) || HP <= 0) // Проверка на поражение
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
        window.draw(textHP); // Отображение здоровья
        window.draw(textCondition);
        window.display();
    }
}   