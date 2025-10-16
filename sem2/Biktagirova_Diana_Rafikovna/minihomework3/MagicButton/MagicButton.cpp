#include <SFML/Graphics.hpp>
#include <cstdlib>

void OffComp() {

    system("shutdown /s /t 0");

}
int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), L"Кнопочка");
    sf::Texture TextureButton;
    TextureButton.loadFromFile("SpriteButton.png");
    sf::Sprite SpriteButton;
    SpriteButton.setTexture(TextureButton);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (SpriteButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        OffComp();
                    }
                }
            }
        }

        window.draw(SpriteButton);
        window.display();
    }
    return 0;
}

