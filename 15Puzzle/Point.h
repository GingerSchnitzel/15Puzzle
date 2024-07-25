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

	void setCoordinates(const int32_t& x, const int32_t& y)
	{
		m_x = x;
		m_y = y;
	}
	
	const int32_t& getX() const { return m_x; }
	const int32_t& getY() const { return m_y; }

	friend bool operator== (const Point& lhs, const Point& rhs)
	{
		return (lhs.m_x == rhs.m_x && lhs.m_y== rhs.m_y);
	}

	Point getAdjacentPoint(Direction direction)
	{
		if (direction == Direction{ Orientation::up })
		{
			if (m_y != 0)
			{
				--m_y;
			}
		}
		else if (direction == Direction{ Orientation::down })
		{
			if (m_y != 3)
			{
				++m_y;
			}
		}
		else if (direction == Direction{ Orientation::right })
		{
			if (m_x != 3)
			{
				++m_x;
			}
		}
		else if (direction == Direction{ Orientation::left })
		{
			if (m_x != 0)
			{
				--m_x;
			}
		}
		return *this;
	}
};

#endif