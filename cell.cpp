#include "cell.h"

void cell::render(void)
{
}

void cell::setObject(baseObject* newObject)
{
	if (newObject) thisObject = newObject;
}
