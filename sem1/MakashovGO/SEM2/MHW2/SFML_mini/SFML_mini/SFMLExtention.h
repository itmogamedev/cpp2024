#pragma once
#ifndef BUT
#define BUT

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <functional>

class Button : public sf::Drawable
{
public:
	Button(sf::RectangleShape shape);
	virtual ~Button() = default;
	void setPosition(sf::Vector2f newPos);
	void setSize(sf::Vector2f newSize);
	virtual void setTexture(sf::Texture& texture);
	void setTextureRect(sf::IntRect rect);
	void setFunc(std::function<void()> _fn);
	sf::Vector2f getPosition();
	bool isClick(sf::Vector2f mousePos);
	virtual void use();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	sf::RectangleShape shape;
	std::function<void()> func;
};

class FlipButton : public Button
{
public:
	FlipButton(sf::RectangleShape shape) : Button(shape) { isFlip = false; }
	~FlipButton() = default;
	void setTexture(sf::Texture& first, sf::Texture& second);
	void use() override;
private:
	sf::Texture first, second;
	bool isFlip;
};

#endif // !BUT