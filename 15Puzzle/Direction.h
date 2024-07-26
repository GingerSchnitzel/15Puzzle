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

	const Orientation& getOrientation() const;
	operator Orientation() const;
	Direction operator-() const;
	friend std::ostream& operator<<(std::ostream& stream, Direction direction);
	static Direction selectRandomDirection();

};

#endif