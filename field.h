#pragma once
//include "baseObject.h"
#include "wall.h"
#include "food.h"
#include "snake.h"

#include "coordinates.h"
#include <SFML/Graphics.hpp>

class baseObject;

class field{
public:
	field(sf::RenderWindow* newWindow, int newColummsCount, int newRowsCount, int newAreaSize, int newFoodCount);
	~field() = default;

	void render();

	int getHeight();
	int getWidth();
	int getRowsCount();
	int getColummnsCount();
	int getCellSize();
	int getFoodCount();
	
	baseObject* getObjectByPosition(coordinates position);
	std::vector<coordinates> getFreePositions();
	sf::RenderWindow* getWindow();
	void insertSnake(snake* newSnake);
	snake* getSnake();
	void update();

protected:
	int cellSize = 0, colummnsCount = 0, rowsCount = 0, foodCount = 0;

	std::vector<wall> walls;
	std::vector<food> foods;
	snake* mySnake = nullptr;
	sf::RenderWindow* myWindow = nullptr;
};
