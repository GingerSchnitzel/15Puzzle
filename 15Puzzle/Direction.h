#ifndef DIRECTION_H
#define DIRECTION_H
#include <random>
#include <cstdint>

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
	Orientation selectRandomOrientation() 
	{
		static std::random_device rd{};                                                 // Random device for seeding the twister
		static std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };      // std::seed_seq resolves underseeding issues 
		static std::mt19937 engine(ss);
		std::uniform_int_distribution<size_t> dist(0, static_cast<size_t>(Orientation::max_orientation) - 1);
		size_t position = dist(engine);

		return static_cast<Orientation>(position);

	}
}

class Direction
{
private:
	Orientation m_orientation;
	
public:
	Direction(Orientation orientation)
		:m_orientation{orientation}
	{}

	const Orientation& getOrientation() const { return m_orientation; }

};

#endif