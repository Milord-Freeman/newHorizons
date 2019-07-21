#include "baseObject.h"

coordinates baseObject::getPosition()
{
	return position;
}

void baseObject::setPosition(coordinates newPosition)
{
	position = newPosition;
}

void baseObject::setPosition(int newX, int newY)
{
	position.x = newX;
	position.y = newY;
}

field* baseObject::getField()
{
	return myField;
}

void baseObject::setField(field* newField)
{
	myField = newField;
}

