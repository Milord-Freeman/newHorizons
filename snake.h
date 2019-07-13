#pragma once
#include "body.h"
#include <vector>

class snake
{
public:
	snake() = default;
	~snake() = default;

protected:
	std::vector<body> snakeBody;
};

