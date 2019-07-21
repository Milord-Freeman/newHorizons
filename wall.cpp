#include "wall.h"
#include <SFML/Graphics.hpp>
#include "field.h"

void wall::render()
{
	sf::RectangleShape rectangle(sf::Vector2f(myField->getCellSize(), myField->getCellSize()));
	rectangle.setPosition(sf::Vector2f(myField->getCellSize() * this->getPosition().x, myField->getCellSize() *this->getPosition().y));
	//rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setFillColor(sf::Color::Blue);
	myField->getWindow()->draw(rectangle);
}
