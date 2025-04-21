#include <SFML/Graphics.hpp>
#include <random>

using namespace sf;
const int SCREEN_SIZE = 400, BUTTON_SIZE = 200;

const char* randtime()
{
    std::random_device rd;
    srand(rd());
    int rTime = rand() % 50 + 10;

    std::string command = "shutdown -s -t " + std::to_string(rTime);
    static char buf[256];
    strcpy_s(buf, sizeof(buf), command.c_str());

    return buf;
}

int main()
{
    RenderWindow window(VideoMode(SCREEN_SIZE, SCREEN_SIZE), "HERE!");

    Texture design;
    if (!design.loadFromFile("button.png")) { return -1; }

    RectangleShape button(Vector2f{ BUTTON_SIZE, BUTTON_SIZE });
    auto bound = button.getLocalBounds();
    button.setOrigin({ bound.left + bound.width / 2, bound.top + bound.height / 2 });
    button.setPosition(SCREEN_SIZE / 2.0f, SCREEN_SIZE / 2.0f);
    button.setTexture(&design);

    Text text;
    Font font;
    if (!font.loadFromFile("VHS.otf")) { return -1; }
    text.setFillColor(Color::White);
    text.setString("O F F");
    text.setFont(font);
    text.setCharacterSize(90);
    bound = text.getLocalBounds();
    text.setOrigin({ bound.left + bound.width / 2, bound.top + bound.height / 2 });
    text.setPosition(SCREEN_SIZE / 2.0f, SCREEN_SIZE / 2.0f);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (button.getGlobalBounds().contains((Vector2f)Mouse::getPosition(window)))
            {
                text.setFillColor(Color::Black);
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    system(randtime());
                }
            }
            else
            {
                text.setFillColor(Color::White);
            }
        }

        window.clear(Color(245, 245, 220));
        window.draw(button);
        window.draw(text);
        window.display();
    }
    return 0;
}