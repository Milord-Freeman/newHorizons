#pragma once
#include "baseObject.h"
#include "baseObject.h"

class field : public baseObject {
public:
	field() = default;
	~field() = default;

	void render(void);
	int getHeight();
	int getWidth();
	int getAreaSize();
	void setHeight(int newHeight);
	void setWidth(int newWidht);
	void setAreaSize(int newAreaSize);

protected:
	int height, width, areaSize;
};
