#include "field.h"

field::field(sf::RenderWindow* newWindow, int newColumms, int newRows, int newAreaSize)
{
	setName("Test snake");
	setAreaSize(newAreaSize);
	setColummnsCount(newColumms);
	setRowsCount(newRows);
	myWindow = newWindow;
	myWindow->create(sf::VideoMode(getWidth(), getHeight()), getName());
}

void field::render(void)
{
	for (int c = 0; c < this->getWidth() / this->getAreaSize(); c++) {
		sf::Vertex vertLine[] =
		{
			sf::Vertex(sf::Vector2f(c * this->getAreaSize(), 0), sf::Color::Green),
			sf::Vertex(sf::Vector2f(c * this->getAreaSize(), getHeight()), sf::Color::Blue)
		};
		myWindow->draw(vertLine, 2, sf::Lines);
	};
	for (int r = 0; r < this->getHeight() / this->getAreaSize(); r++) {
		sf::Vertex horLine[] =
		{
			sf::Vertex(sf::Vector2f(0, r * this->getAreaSize()), sf::Color::Red),
			sf::Vertex(sf::Vector2f(getWidth(), r * this->getAreaSize()), sf::Color::Blue)
		};
		myWindow->draw(horLine, 2, sf::Lines);
	};
}
int field::getHeight()
{
	return getRowsCount() * getAreaSize();
}
int field::getWidth()
{
	return getColummnsCount() * getAreaSize();
}
int field::getRowsCount()
{
	return rows;
}
int field::getColummnsCount()
{
	return colummns;
}
int field::getAreaSize()
{
	return areaSize;
}
void field::setAreaSize(int newAreaSize)
{
	areaSize = newAreaSize;
}
void field::setRowsCount(int newRowsCount)
{
	rows = newRowsCount;
}
void field::setColummnsCount(int newColummnsCount)
{
	colummns = newColummnsCount;
}

cell* field::getCellByPosition(coordinates position)
{
	for (auto& currentCell : cells) {
		if (currentCell.getPosition() == position) return &currentCell;
	}
	return nullptr;
}

