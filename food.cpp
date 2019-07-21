#include "food.h"
#include <SFML/Graphics.hpp>
#include "field.h"

void food::render()
{
	sf::RectangleShape rectangle(sf::Vector2f(myField->getCellSize(), myField->getCellSize()));
	rectangle.setPosition(sf::Vector2f(myField->getCellSize() * this->getPosition().x, myField->getCellSize() * this->getPosition().y));
	rectangle.setFillColor(sf::Color::Yellow);
	myField->getWindow()->draw(rectangle);
}
