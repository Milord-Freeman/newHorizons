#pragma once

class baseObject {
public:
	baseObject() = default;
	virtual ~baseObject() = default;
	
	virtual void render(void) = 0;
	virtual void stepped() = 0;
	
protected:

};