#include "field.h"

void field::render(void)
{
	for (int c = 0; c < this->getWidth() / this->getAreaSize(); c++) {
		sf::Vertex vertLine[] =
		{
			sf::Vertex(sf::Vector2f(c * this->getAreaSize(), 0), sf::Color::Green),
			sf::Vertex(sf::Vector2f(c * this->getAreaSize(), getHeight()), sf::Color::Blue)
		};
		myWindow->draw(vertLine, 2, sf::Lines);
	};
	for (int r = 0; r < this->getHeight() / this->getAreaSize(); r++) {
		sf::Vertex horLine[] =
		{
			sf::Vertex(sf::Vector2f(0, r * this->getAreaSize()), sf::Color::Red),
			sf::Vertex(sf::Vector2f(getWidth(), r * this->getAreaSize()), sf::Color::Blue)
		};
		myWindow->draw(horLine, 2, sf::Lines);
	};
}
int field::getHeight()
{
	return height;
}
int field::getWidth()
{
	return width;
}
int field::getAreaSize()
{
	return areaSize;
}

void field::setHeight(int newHeight)
{
	height = newHeight;
}

void field::setWidth(int newWidht)
{
	width = newWidht;
}

void field::setAreaSize(int newAreaSize)
{
	areaSize = newAreaSize;
}

