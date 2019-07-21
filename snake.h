#pragma once
#include "body.h"
#include <vector>

enum direction
{
	LEFT, RIGHT, UP, DOWN
};

class snake
{
public:

	snake(field* newField, direction startDirection, int newLength);
	~snake() = default;

	std::vector<body>* getBody();
	//void addBody(coordinates newPosition);
	//void changeDirection(direction newDirection);
	void makeNextStep();
	
	int getLength();
	void setHeadPosition(coordinates newPosition);
	coordinates getNextStepPosition();

	void render();

protected:

	std::vector<body> snakeBody;
	direction currentDirection = LEFT;
	bool changedDirection = false;
	field* myField = nullptr;
	int length = 0;
	coordinates headPosition = { 5, 6 };
	coordinates nextStepPosition = headPosition;

};


