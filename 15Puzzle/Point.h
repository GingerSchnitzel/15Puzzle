#ifndef POINT_H
#define POINT_H

#include <utility>
#include <cstdint>
#include "Direction.h"


class Point
{
private:
	int32_t m_x;
	int32_t m_y;

public:

	Point() = default;
	Point(int32_t x, int32_t y)
		: m_x {x}
		, m_y {y}
	{}

	void setCoordinates(const int32_t& x, const int32_t& y);
	const int32_t& getX() const;
	const int32_t& getY() const;
	friend bool operator== (const Point& lhs, const Point& rhs);
	Point getAdjacentPoint(Direction direction);
};

#endif