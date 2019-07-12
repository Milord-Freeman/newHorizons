#include "coordinates.h"
const bool operator==(const coordinates& left, coordinates& right) {
	return (left.x == right.x && left.y == right.y);
}