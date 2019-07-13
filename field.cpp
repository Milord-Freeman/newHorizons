#include "field.h"

field::field(sf::RenderWindow* newWindow, int newColumms, int newRows, int newCellSize)
{
	this->cellSize = newCellSize;
	this->colummnsCount = newColumms;
	this->rowsCount = newRows;
	this->myWindow = newWindow;

	myWindow->create(sf::VideoMode(getWidth(), getHeight()), "test Snake");

	//for (int x = 0; x < this->getColummnsCount(); x++)
	//{
	//	for (int y = 0; y < this->getRowsCount(); y++)
	//	{
	//		coordinates currentPosition = { x, y };
	//		if ((x == 0) || (y == 0) || (x == this->getColummnsCount()) || ( y == this->getRowsCount() ))
	//		{
	//			this->walls.push_back(*new wall(newWindow, currentPosition));
	//		}
	//		this->cells.push_back(*new cell(newWindow, currentPosition));
	//
	//	}
	//}
}

void field::render(void)
{
	for (int c = 0; c < this->getWidth() / this->getCellSize(); c++) {
		sf::Vertex vertLine[] =
		{
			sf::Vertex(sf::Vector2f(c * this->getCellSize(), 0), sf::Color::Green),
			sf::Vertex(sf::Vector2f(c * this->getCellSize(), getHeight()), sf::Color::Blue)
		};
		myWindow->draw(vertLine, 2, sf::Lines);
	};
	for (int r = 0; r < this->getHeight() / this->getCellSize(); r++) {
		sf::Vertex horLine[] =
		{
			sf::Vertex(sf::Vector2f(0, r * this->getCellSize()), sf::Color::Red),
			sf::Vertex(sf::Vector2f(getWidth(), r * this->getCellSize()), sf::Color::Blue)
		};
		myWindow->draw(horLine, 2, sf::Lines);
	};
	for (auto currentCell : cells)
	{
		currentCell.render();
	}
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
cell* field::getCellByPosition(coordinates position)
{
	for (auto& currentCell : cells) {
		if (currentCell.getPosition() == position) return &currentCell;
	}
	return nullptr;
}
std::vector<cell*> field::getFreeCells()
{
	std::vector<cell*> freeCells;
	for (auto& currentCell : cells)	{
		if (currentCell.isFree()) freeCells.push_back(&currentCell);
	}
	return freeCells;
}

