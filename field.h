#pragma once
#include "cell.h"
#include "wall.h"
#include "food.h"
#include "snake.h"
#include "coordinates.h"
#include <SFML/Graphics.hpp>


class field{
public:
	field(sf::RenderWindow* newWindow, int newColummsCount, int newRowsCount, int newAreaSize);
	~field() = default;

	void render();
	int getHeight();
	int getWidth();
	int getRowsCount();
	int getColummnsCount();
	int getCellSize();
	
	cell* getCellByPosition(coordinates position);
	std::vector<cell*> getFreeCells();

protected:
	int cellSize = 0, colummnsCount = 0, rowsCount = 0;
	std::vector<cell> cells;
	std::vector<wall> walls;
	std::vector<food> foods;
	snake mySnake;
	sf::RenderWindow* myWindow = nullptr;
};
