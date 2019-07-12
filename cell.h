#pragma once
#include "baseObject.h"

class cell : public baseObject {
public:
	//void render(void);
	virtual void stepped() = 0;
	baseObject* getObject();
	void setObject(baseObject* newObject);
protected:
	baseObject* thisObject;
};

