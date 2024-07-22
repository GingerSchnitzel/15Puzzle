#ifndef TILE_H
#define TILE_H
#include <iostream>
#include <cstdint>
/*
* CLASS TILE
* Display an individual tile
*/

class Tile
{
private:
	int32_t m_number;

public:
	Tile() = default;

	explicit Tile(int32_t number)
		: m_number(number)
	{

	}

	const int32_t& getNumber() const { return m_number; }
	bool isEmpty() const { return (m_number == 0); }

	friend std::ostream& operator<< (std::ostream& out, const Tile& tile)
	{
		if (tile.m_number > 9) 
			out << " " << tile.m_number << " ";
		else if (tile.m_number > 0) 
			out << "  " << tile.m_number << " ";
		else if (tile.m_number == 0) 
			out << "    ";
		return out;
	}
};

#endif