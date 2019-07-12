#include "baseObject.h"

baseObject::baseObject(sf::RenderWindow *newWindow)
{
	position.x = 0; 
	position.y = 0; 
	color = 0; 
	myWindow = new sf::RenderWindow;
}; 
baseObject::baseObject()
{
	position.x = 0; 
	position.y = 0; 
	color = 0;
};

baseObject::~baseObject() = default;

coordinates baseObject::getPosition()
{
	return position;
};

void baseObject::setPosition(int newX, int newY)
{
	position.x = newX; 
	position.y = newY;
}

int baseObject::getColor()
{
	return color;
}

void baseObject::setColor(int newColor)
{
	color = newColor;
}

std::string baseObject::getName()
{
	return name;
};
void baseObject::setName(std::string newName)
{
	name = newName;
};
