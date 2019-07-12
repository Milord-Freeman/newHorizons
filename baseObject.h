#include <string>
#include "SFML/Graphics.hpp"
#include "coordinates.h"

#pragma once
class baseObject {
public:
	baseObject();
	baseObject(sf::RenderWindow* newWindow);
	~baseObject();
	coordinates getPosition();
	void setPosition(int newX, int newY);
	int getColor();
	void setColor(int newColor);
	std::string getName();
	void setName(std::string newName);
	virtual void render(void) = 0;
	sf::RenderWindow* myWindow;

protected:
	coordinates position;
	int color;
	std::string name;
};