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
