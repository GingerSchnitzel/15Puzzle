#include "Direction.h"

Orientation Random::selectRandomOrientation()
{
	static std::random_device rd{};                                                 // Random device for seeding the twister
	static std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };      // std::seed_seq resolves underseeding issues 
	static std::mt19937 engine(ss);
	std::uniform_int_distribution<size_t> dist(0, static_cast<size_t>(Orientation::max_orientation) - 1);
	size_t position = dist(engine);

	return static_cast<Orientation>(position);

}

std::ostream& operator<<(std::ostream& stream, Direction direction)
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

const Orientation& Direction::getOrientation() const { return m_orientation; }

Direction::operator Orientation() const { return m_orientation; }

Direction Direction::operator-() const
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

Direction Direction::selectRandomDirection()
{
	return (static_cast<Direction>(Random::selectRandomOrientation()));
}
