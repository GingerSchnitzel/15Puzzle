#ifndef POINT_H
#define POINT_H

#include <utility>
#include <cstdint>
#include "Direction.h"



class Point
{
private:
	std::pair <int32_t, int32_t> m_coordinates;

public:

	Point() = default;
	Point(int32_t x, int32_t y)
		: m_coordinates{ x,y }
	{}

	friend bool operator== (const Point& lhs, const Point& rhs)
	{
		return (lhs.m_coordinates.first == rhs.m_coordinates.first && lhs.m_coordinates.second == rhs.m_coordinates.second);
	}

	Point getAdjacentPoint(Direction direction)
	{
		if (direction == Direction{ Orientation::up })
		{
			if (m_coordinates.second != 0)
			{
				--m_coordinates.second;
			}
			std::cout << "Can't move up anymore!\n";
		}
		else if (direction == Direction{ Orientation::down })
		{
			if (m_coordinates.second != 3)
			{
				++m_coordinates.second;
			}
			std::cout << "Can't move down anymore!\n";
		}
		else if (direction == Direction{ Orientation::right })
		{
			if (m_coordinates.first != 3)
			{
				++m_coordinates.first;
			}
			std::cout << "Can't move right anymore!\n";
		}
		else if (direction == Direction{ Orientation::left })
		{
			if (m_coordinates.first != 0)
			{
				--m_coordinates.first;
			}
			std::cout << "Can't move left anymore!\n";
		}
		return *this;
	}
};

#endif