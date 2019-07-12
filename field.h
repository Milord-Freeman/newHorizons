#pragma once
#include "baseObject.h"
#include "cell.h"
#include <vector>

class field : public baseObject {
public:
	field(sf::RenderWindow * newWindow, int newColumms, int newRows, int newAreaSize);
	~field() = default;

	void render(void);
	int getHeight();
	int getWidth();
	int getRowsCount();
	int getColummnsCount();
	int getAreaSize();
	void setAreaSize(int newAreaSize);
	void setRowsCount(int newRowsCount);
	void setColummnsCount(int newColummnsCount);
	cell* getCellByPosition(coordinates position);

protected:
	int areaSize, colummns, rows;
	std::vector<cell> cells;

};
