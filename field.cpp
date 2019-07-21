#include "field.h"
#include <cstdlib>
#include <ctime>

field::field(sf::RenderWindow* newWindow, int newColumms, int newRows, int newCellSize, int newFoodCount)
{
	this->cellSize = newCellSize;
	this->colummnsCount = newColumms;
	this->rowsCount = newRows;
	this->myWindow = newWindow;
	this->foodCount = newFoodCount;

	myWindow->create(sf::VideoMode(getWidth(), getHeight()), "test Snake");

	for (int x = 0; x < this->getColummnsCount(); x++)
	{
		for (int y = 0; y < this->getRowsCount(); y++)
		{
			if ((x == 0) || (y == 0) || (x == this->getColummnsCount() - 1) || (y == this->getRowsCount() - 1))
			{
				wall currentWall;
				currentWall.setField(this);
				currentWall.setPosition(x, y);
				walls.push_back(currentWall);
			}
		}
	}

	srand(time(NULL));

	for (int i = 0; i < this->getFoodCount(); i++)
	{
		std::vector<coordinates> currentFreePositions = this->getFreePositions();
		coordinates currentRandomPosition = currentFreePositions[rand() % currentFreePositions.size()];
		food currentFood;
		currentFood.setField(this);
		currentFood.setPosition(currentRandomPosition);
		foods.push_back(currentFood);
	}

}

void field::render(void)
{
	for (int c = 0; c < this->getColummnsCount(); c++) {
		sf::Vertex vertLine[] =
		{
			sf::Vertex(sf::Vector2f(c * this->getCellSize(), 0), sf::Color::Green),
			sf::Vertex(sf::Vector2f(c * this->getCellSize(), getHeight()), sf::Color::Blue)
		};
		myWindow->draw(vertLine, 2, sf::Lines);
	};

	for (int r = 0; r < this->getRowsCount(); r++) {
		sf::Vertex horLine[] =
		{
			sf::Vertex(sf::Vector2f(0, r * this->getCellSize()), sf::Color::Red),
			sf::Vertex(sf::Vector2f(getWidth(), r * this->getCellSize()), sf::Color::Blue)
		};
		myWindow->draw(horLine, 2, sf::Lines);
	};

	for (auto currentWall : walls)
	{
		currentWall.render();
	}

	for (auto currentFood : foods)
	{
		currentFood.render();
	}

	if (mySnake) mySnake->render();
}

int field::getHeight()
{
	return getRowsCount() * getCellSize();
}
int field::getWidth()
{
	return getColummnsCount() * getCellSize();
}
int field::getRowsCount()
{
	return rowsCount;
}
int field::getColummnsCount()
{
	return colummnsCount;
}
int field::getCellSize()
{
	return cellSize;
}
int field::getFoodCount()
{
	return foodCount;
}
baseObject* field::getObjectByPosition(coordinates position)
{
	for (auto& currentWall : walls)
	{
		if (currentWall.getPosition() == position)
		{
			return &currentWall;
		}
	}

	//for (auto& currentFood : foods)
	//{
	//	if (currentFood.getPosition() == position )
	//	{
	//		return &currentFood;
	//	}
	//}
	//
	//for (auto& currentBody: mySnake.getBody())
	//{
	//	if (currentBody.getPosition() == position )
	//	{
	//		return &currentBody;
	//	}
	//}

	return nullptr;
}
sf::RenderWindow* field::getWindow()
{
	return myWindow;
}
std::vector<coordinates> field::getFreePositions()
{
	std::vector<coordinates> freePositions;

	for (int x = 0; x < this->getColummnsCount(); x++)
	{
		for (int y = 0; y < this->getRowsCount(); y++)
		{
			coordinates currentPosition = { x, y };
			if (!this->getObjectByPosition(currentPosition))
			{
				freePositions.push_back(currentPosition);
			}
		}
	}
	return freePositions;
}
void field::insertSnake(snake* newSnake)
{
	mySnake = newSnake;
}
snake* field::getSnake()
{
	return mySnake;
}
void field::update()
{
	mySnake->makeNextStep();
}
