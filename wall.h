#pragma once
#include "cell.h"
#include "baseObject.h"

class wall : public baseObject {
public:
	wall() = default;
	~wall() = default;

	void render();
	void stepped();

protected:
	cell* myCell = nullptr;
};
