#include "snake.h"
#include "field.h"

snake::snake(field* newField, direction startDirection, int newLength)
{
	
	myField = newField;
	length = newLength;
	currentDirection = startDirection;

	std::vector<coordinates> currentFreePositions = myField->getFreePositions();
	std::vector<coordinates> availableForSnakePositions;
	for (auto currentPosition : currentFreePositions)
	{
		if ((currentPosition.x > this->getLength()) && 
			(currentPosition.y > this->getLength()) &&
			(currentPosition.x < (myField->getColummnsCount() - this->getLength())) &&
			(currentPosition.y < (myField->getRowsCount() - this->getLength())))	
		{
			availableForSnakePositions.push_back(currentPosition);
		}
	}
	this->setHeadPosition(availableForSnakePositions.at(rand() % availableForSnakePositions.size()));
}

void snake::setHeadPosition(coordinates newPosition)
{
	headPosition = newPosition;
	snakeBody.clear();
	for (int i = getLength(); i > 0; i--)
	{
		coordinates currentPosition = headPosition;
		switch (currentDirection) {
		case LEFT: {currentPosition.x -= i;	break; }
		case RIGHT: {currentPosition.x += i;	break; }
		case DOWN: {currentPosition.y += i;	break; }
		case UP: {currentPosition.y -= i;	break; }
		default: break;
		}
		body currentBody;
		currentBody.setField(this->myField);
		currentBody.setPosition(currentPosition);
		snakeBody.push_back(currentBody);
	}
}


int snake::getLength()
{
	return length;
}

std::vector<body>* snake::getBody()
{
	return &snakeBody;
}

void snake::render()
{
	for (auto currentBody : snakeBody)
	{
		currentBody.render();
	}
}

//coordinates snake::getNextStepPosition()
//{
//		
//}

void snake::makeNextStep()
{
	//headPosition == nextStepPosition;
	if (myField->getObjectByPosition(nextStepPosition))
	{
		//do something
	}
	else
	{
		headPosition == nextStepPosition;
		coordinates bufferPosition;
		for (int i = 0; i < snakeBody.size()-1; i++)
		{
			snakeBody[i].setPosition(snakeBody[i + 1].getPosition());
		}
		snakeBody[snakeBody.size()-1].setPosition(headPosition);
	}

}

