#pragma once
#include "cell.h"
#include "baseObject.h"

class food : public baseObject{

public:
	food() = default;
	~food() = default;

	void render();
	void stepped();

protected:
	cell* myCell = nullptr;

};

