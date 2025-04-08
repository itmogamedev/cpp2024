#include "SFMLExtention.h"

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape);
}

Button::Button(sf::RectangleShape _shape)
{
	shape = _shape;
}

void Button::setPosition(sf::Vector2f newPos)
{
	shape.setPosition(newPos);
}

void Button::setSize(sf::Vector2f newSize)
{
	shape.setSize(newSize);
}

void Button::setTexture(sf::Texture& texture)
{
	shape.setTexture(&texture);
}

void Button::setTextureRect(sf::IntRect rect)
{
	shape.setTextureRect(rect);
}

void Button::setFunc(std::function<void()> _fn)
{
	func = _fn;
}

sf::Vector2f Button::getPosition()
{
	return shape.getPosition();
}

bool Button::isClick(sf::Vector2f mousePos)
{
	auto x0 = shape.getPosition().x, x1 = x0 + shape.getSize().x;
	auto y0 = shape.getPosition().y, y1 = y0 + shape.getSize().y;
	if (mousePos.x > x0 && mousePos.x < x1 && mousePos.y > y0 && mousePos.y < y1)
	{
		return true;
	}
	return false;
}

void Button::use()
{
	if (func) func();
}

void FlipButton::setTexture(sf::Texture& _first, sf::Texture& _second)
{
	first = _first;
	second = _second;
	shape.setTexture(&_first);
}

void FlipButton::use()
{
	if (!isFlip)
	{
		shape.setTexture(&second);
		isFlip = true;
		if (func) func();
	}
}
