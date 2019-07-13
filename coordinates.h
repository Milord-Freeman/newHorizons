#pragma once

struct coordinates
{
	int x = 0, y = 0;
	bool operator == (const coordinates& other) {
		return ((&other == this ) || (this->x == other.x && this->y == other.y));
	}
};

