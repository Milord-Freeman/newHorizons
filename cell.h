#pragma once
#include "baseObject.h"
#include "coordinates.h"

class field;

class cell : public baseObject {
public:
	cell(field* newField, coordinates newPosition);
	~cell() = default;

	void render();
	void stepped();


	baseObject* getObject();
	void insertObject(baseObject* newObject);

	field* getField();
	coordinates getPosition();
	bool isFree();

protected:
	coordinates position;
	baseObject* insertedObject = nullptr;
	field* myField = nullptr;	
};

