#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <cstdint>

class Tile
{
private:
	int32_t m_number;

public:
	Tile() = default;

	explicit Tile(int32_t number)
		: m_number(number)
	{}

	const int32_t& getNumber() const;
	bool isEmpty() const;
	friend std::ostream& operator<< (std::ostream& out, const Tile& tile);
	friend bool operator==(const Tile& lhs, const Tile& rhs);
};

#endif