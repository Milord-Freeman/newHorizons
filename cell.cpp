#include "cell.h"

cell::cell(field* newField, coordinates newPosition)
{
	this->myField = newField;
	this->position = newPosition;
}

void cell::render(void)
{
	//if (insertedObject)
	//{
	//	insertedObject->render();
	//}
	//else
	//{
	//	sf::RectangleShape rectangle(sf::Vector2f(18, 18));
	//	rectangle.setPosition(sf::Vector2f((this->getPosition().x * 20 +1 ), (this->getPosition().y * 20 + 1)));
	//	rectangle.setFillColor(sf::Color::Cyan);
	//	myWindow->draw(rectangle);
	//}
}

void cell::stepped()
{

}

baseObject* cell::getObject()
{
	return insertedObject;
}

void cell::insertObject(baseObject* newObject)
{
	if (newObject) insertedObject = newObject;
}

field* cell::getField()
{
	return myField;
}

coordinates cell::getPosition()
{
	return position;
}

bool cell::isFree()
{
	return (insertedObject == nullptr);
}
