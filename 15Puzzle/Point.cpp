#include "Point.h"

 void Point::setCoordinates(const int32_t& x, const int32_t& y)
{
	m_x = x;
	m_y = y;
}

 const int32_t& Point::getX() const { return m_x; }

 const int32_t& Point::getY() const { return m_y; }

 Point Point::getAdjacentPoint(Direction direction)
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

bool operator==(const Point& lhs, const Point& rhs)
{
	return (lhs.m_x == rhs.m_x && lhs.m_y == rhs.m_y);
}
