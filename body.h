#pragma once
#include "baseObject.h"
class body : public baseObject{

public:
	body() = default;
	~body() = default;

	void render();
	void stepped();

protected:
	body* myCell = nullptr;
};

