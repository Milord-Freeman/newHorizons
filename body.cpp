#include "body.h"
#include <SFML/Graphics.hpp>
#include "field.h"

void body::render()
{
	sf::RectangleShape rectangle(sf::Vector2f(myField->getCellSize(), myField->getCellSize()));
	rectangle.setPosition(sf::Vector2f(myField->getCellSize() * this->getPosition().x, myField->getCellSize() * this->getPosition().y));
	rectangle.setFillColor(sf::Color::Green);
	myField->getWindow()->draw(rectangle);
}