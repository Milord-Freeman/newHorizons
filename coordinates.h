#pragma once

struct coordinates
{
	int x, y;
	const bool operator == (const coordinates& other) {
		return ((&other == this ) || (this->x == other.x && this->y == other.y));
	}
};

