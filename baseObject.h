#pragma once

#include "coordinates.h"

class field;

class baseObject
{
public:
	baseObject() = default;
	virtual ~baseObject() = default;

	virtual void render() = 0;

	coordinates getPosition();
	void setPosition(coordinates newPosition);
	void setPosition(int newX, int newY);

	void setField(field* newField);
	field* getField();

protected:
	coordinates position = {0, 0};
	field* myField = nullptr;
};

