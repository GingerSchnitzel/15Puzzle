#ifndef DIRECTION_H
#define DIRECTION_H

#include <random>
#include <cstdint>
#include <cassert>
#include <iostream>


enum class Orientation
{
	up,
	down,
	left,
	right,
	max_orientation
};

namespace Random
{
	Orientation selectRandomOrientation();
}

class Direction
{
private:
	Orientation m_orientation;

public:
	
	explicit Direction(Orientation orientation)
		:m_orientation{ orientation }
	{}

	const Orientation& getOrientation() const { return m_orientation; }

	operator Orientation() const { return m_orientation; }


	Direction operator-() const
	{
		switch (m_orientation)
		{
		case Orientation::up:    return Direction{ Orientation::down };
		case Orientation::down:  return Direction{ Orientation::up };
		case Orientation::left:  return Direction{ Orientation::right };
		case Orientation::right: return Direction{ Orientation::left };
		default: assert(false && "Unsupported direction was passed!");
		}
		return Direction{ Orientation::up };
	}

	friend std::ostream& operator<<(std::ostream& stream, Direction direction)
	{
		switch (direction.getOrientation())
		{
		case Orientation::up:     return (stream << "up");
		case Orientation::down:   return (stream << "down");
		case Orientation::left:   return (stream << "left");
		case Orientation::right:  return (stream << "right");
		default:                  return (stream << "unknown direction");
		}
	}

	static Direction selectRandomDirection()
	{
		return (static_cast<Direction>(Random::selectRandomOrientation()));
	}

};

#endif